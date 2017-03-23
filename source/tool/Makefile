#
# @file    tool/Makefile
# @repo    gruppe32
# @created 23.03.17 by Jonas
# @brief - this Makefile was inspired by this tutorial
#           http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# 
# @dictionary
#   '$@' - References all the stuff to the left of the ':'
#   '$<' - First argument to the right of ':'
#   '$^' - All arguments to the right of ':'

CC=g++
CFLAGS=-Wall -g -I.

BDIR=../../compile/build
ODIR=../../compile/object

_OBJ=tool.o
OBJ=$(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(%.h)
		$(CC) -c -o $@ $< $(CFLAGS)

tool: $(OBJ)
		$(CC) -o $(BDIR)/$@ $< $(CFLAGS)

run:
	./$(BDIR)/tool
