CC = gcc
CFLAGS = -Wall
DEPS = tabbin.h
ODIR = obj
_OBJ = 
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))
OBJPILE = $(CC) $(CFLAGS) -c -o $@     $<
COMPILE = $(CC) $(CFLAGS)    -o $@.elf $^ 

$(ODIR)/%.o: %.c $(DEPS)
	 $(OBJPILE)

detab: $(ODIR)/detab.o $(ODIR)/tabbin.lb.o
	$(COMPILE)

entab: $(ODIR)/entab.o $(ODIR)/tabbin.lb.o
	$(COMPILE)
