IDIR = ../include
CC = g++
# CFLAGS =
TESTDIR = tf

ODIR = obj
LDIR = ../lib

LIBS = -lm

_DEPS = file_manager.h text_manager.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o file_manager.o text_manager.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< #$(CFLAGS)

task_2: $(OBJ)
	$(CC) -o $@ $^ # $(CFLAGS) $(LIBS)
	./test

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
