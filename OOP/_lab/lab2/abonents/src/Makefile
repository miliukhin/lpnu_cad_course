# this makefile should be in src/
# The .PHONY rule keeps make from doing something with a file named clean.

IDIR = ../include
CC = g++
# CFLAGS =

ODIR = obj
LDIR = ../lib

LIBS = -lm

_DEPS = abonent.h abonents.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o abonent.o abonents.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< #$(CFLAGS)

task_2: $(OBJ)
	$(CC) -o $@ $^ # $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

# -o $@ put the output of the compilation in the file named on the left side of the :
# $< the first item in the deps list
# $@ left side of :
# $^ right side of :
