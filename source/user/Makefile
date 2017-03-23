
CC=g++
CFLAGS=-I.

IDIR=header
BDIR=../../compile/build
ODIR=../../compile/object

$(ODIR)/%.o: %.cpp %.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/usermake: $(ODIR)/user.o
	$(CC) -o $@ $^ $(CFLAGS)

run:
	./$(BDIR)/user