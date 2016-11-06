IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)
TARGET = 1 2 3 4 5 6 7 8

ODIR=obj
LDIR =../lib

LIBS=-lm

.PRECIOUS: $(ODIR)/%.o
$(ODIR)/%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

all : $(TARGET)

ch% : $(ODIR)/%.o
		$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(TARGET)
