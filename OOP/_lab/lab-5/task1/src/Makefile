IDIR = ../include
CC = g++
# CFLAGS =

ODIR = obj

LIBS = -lm

_DEPS = hier.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hier.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< #$(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ # $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
