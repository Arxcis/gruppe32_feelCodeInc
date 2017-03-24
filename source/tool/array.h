#pragma once
namespace dat
{
	template<typename T, size_t arr_size>
	struct array
	{
	private:
		size_t count_;

	public:
		T values[arr_size];
		const size_t length = arr_size;
		size_t Count();
	};
}