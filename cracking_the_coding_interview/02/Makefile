IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)
TARGET = test 1 2 3 4 5 6 7

ODIR=obj
LDIR =../lib
LIBS=-lm

all : $(TARGET)

test : test.cpp linkedlist.hpp base.hpp
	$(CC) $(CFLAGS) -o $@ $<

1 : 1.cpp linkedlist.hpp base.hpp
	$(CC) $(CFLAGS) -o $@ $<


.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(TARGET)
