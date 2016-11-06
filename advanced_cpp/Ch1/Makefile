IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)
TARGET = ch0-0 ch0-2 ch0-5

ODIR=obj
LDIR =../lib

LIBS=-lm

#_OBJS = 0-0.o 0-2.o
#OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

#_DEPS = hellomake.h
#DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

.PRECIOUS: $(ODIR)/%.o
$(ODIR)/%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

all : $(TARGET)

ch% : $(ODIR)/%.o
		$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(TARGET)
