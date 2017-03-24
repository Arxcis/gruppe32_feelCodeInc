#
# @file    user/Makefile
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
CFLAGS=-std=c++11 -Wall -g -I.

BDIR=../../compile/build
ODIR=../../compile/object

_OBJ=testingUser.o menu.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(%.h)
		$(CC) -c -o $@ $< $(CFLAGS)

user: $(OBJ)
		$(CC) -o $(BDIR)/$@ $< $(CFLAGS)

run:
	./$(BDIR)/user
