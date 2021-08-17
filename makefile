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

dcl: $(ODIR)/declaration_parser.o $(ODIR)/molon.lb.o dcl.h
	$(COMPILE)

undcl:  $(ODIR)/undcl.o $(ODIR)/molon.lb.o dcl.h
	$(COMPILE)
