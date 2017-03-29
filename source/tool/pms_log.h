#pragma once

// @credit PMS - Per Morten Straume
// @ modified 28.03.17 by Jonas - removed mutex support
// @          29.03.17 chaned std::crbegin and std::crend to std::begin and std::end

#include <cstdio>
#include <cstdarg>
#include <chrono>
#include <algorithm>
#include <iterator>
#include <exception>

struct Timer
{
    using ClockType = std::chrono::high_resolution_clock;
    using TimePoint = decltype(ClockType::now());
    Timer() : startOfProgram(ClockType::now()) {}
    TimePoint startOfProgram;
};

extern Timer g_timer;

template<std::size_t sizeOfFileName>
void
log(const char* type,
    const char* expr,
    const char(&filename)[sizeOfFileName],
    const char* function,
    int line,
    const Timer::TimePoint& timePoint,
    const char* fmt,
    ...)
{
    using Ms = std::chrono::milliseconds;
    double timeInMs =
        std::chrono::duration<double, Ms::period>(timePoint - g_timer.startOfProgram).count();

    const auto filenameStart =
        std::find_if(std::begin(filename),
                     std::end(filename),
                     [](const char value) { return value == '\\' || value == '/'; });

    // %010 = total number of digits (including .)
    constexpr int numberOfDigits = 10;
    constexpr int precision = 3;
    constexpr int maxSourcefileLength = 5;
    constexpr int maxFunctionNameLength = 5;
    constexpr int maxLineNumber = 3;

    const char* format = (expr == nullptr) ? "[%0*.*f][%-7s] %-*s::%-*s: %*i: " : "[%0*.*f][%-7s] %-*s::%-*s: %*i: expr: %s: ";

    std::fprintf(stdout,
                 format,
                 numberOfDigits,
                 precision,
                 timeInMs,
                 type,
             //    maxSourcefileLength,
              //   filenameStart.base(),
                 maxFunctionNameLength,
                 function,
                 maxLineNumber,
                 line,
                 expr);
    std::va_list args;
    va_start(args, fmt);
    std::vfprintf(stdout, fmt, args);
    va_end(args);
}


///////////////////////////////////////////////////////////////////////////////////////////////////
/// \def PMS_DEBUG(fmt,...)
///
/// \brief Macro used for debug related logging.
///
/// DEBUG is for debug related output, such as calculations output or other debug statements.
/// Avoid using debug within loops or other places where it will spam cmd window constantly.
/// When an issue is fixed, please remove the debug output
///
///////////////////////////////////////////////////////////////////////////////////////////////////
#define PMS_DEBUG(fmt,...) \
log<sizeof(__FILE__)>("DEBUG", nullptr, __FILE__, __func__, __LINE__, Timer::ClockType::now(), fmt, ##__VA_ARGS__);

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \def PMS_INFO(fmt,...)
///
/// \brief Macro used for general functionality logging.
///
/// INFO is for nice to know output, like finishing loading a file, sending message etc.
/// Basically stuff that does not spam the cmd window constantly.
///
///////////////////////////////////////////////////////////////////////////////////////////////////
#define PMS_INFO(fmt,...) \
log<sizeof(__FILE__)>("INFO", nullptr, __FILE__, __func__, __LINE__, Timer::ClockType::now(), fmt, ##__VA_ARGS__);

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \def PMS_WARN(fmt,...)
///
/// \brief Macro used for warning related logging.
///
/// WARN is for errors that are recoverable but that still should not happen.
/// Example: Not finding a parameter from the cmd window, or not being able to connect to an IP.
///
///////////////////////////////////////////////////////////////////////////////////////////////////
#define PMS_WARN(fmt,...) \
log<sizeof(__FILE__)>("WARNING", nullptr, __FILE__, __func__, __LINE__, Timer::ClockType::now(), fmt, ##__VA_ARGS__);

///////////////////////////////////////////////////////////////////////////////////////////////////
/// \def PMS_ERROR(fmt,...)
///
/// \brief Macro used for error related logging.
///
/// ERROR is for non-recovarble errors, if this macro is encountered, the program will terminate.
/// Example: Not being able to initialize glew/glfw or not finding a specific shader.
///
///////////////////////////////////////////////////////////////////////////////////////////////////
#define PMS_ERROR(fmt,...) \
log<sizeof(__FILE__)>("ERROR", nullptr, __FILE__, __func__, __LINE__, Timer::ClockType::now(), fmt, ##__VA_ARGS__); \
std::terminate();



///////////////////////////////////////////////////////////////////////////////////////////////////
/// \def PMS_ASSERT(expr, fmt, ...)
///
/// \brief Custom assert function supporting printf style output
///
/// This assert function follows the same logic as c-style assert, except it follows the
/// ftcp standard for printing.
/// Use this assert to make sure function requirements etc are met.
/// This is for internal use only, and will be turned off in release mode.
///
/// \see Taken from: Jason Gregory: Game Engine Architecture. p.150
///////////////////////////////////////////////////////////////////////////////////////////////////
#define PMS_ASSERTIONS_ENABLED
#ifdef PMS_ASSERTIONS_ENABLED
#define PMS_ASSERT(expr, fmt, ...) \
if (expr) { } \
    else \
    { \
        log<sizeof(__FILE__)>("ASSERT", #expr, __FILE__, __func__, __LINE__, Timer::ClockType::now(), fmt, ##__VA_ARGS__); \
        std::fflush(stdout); \
        std::terminate(); \
    }
#else
#define PMS_ASSERT(expr, fmt, ...)
#endif