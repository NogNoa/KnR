CC = gcc
CFLAGS = -Wall
DEPS = tree_count.h
ODIR = obj
_OBJ = 
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))
OBJPILE = $(CC) $(CFLAGS) -c -o $@     $<
COMPILE = $(CC) $(CFLAGS)    -o $@.elf $^ 

$(ODIR)/%.o: %.c $(DEPS)
	 $(OBJPILE)

tree_count: $(ODIR)/tree_count.o $(ODIR)/addtree.o $(ODIR)/talloc.o ../$(ODIR)/molon.lb.o
	$(COMPILE)

cvar: $(ODIR)/cvar_count.o $(ODIR)/addtree.o $(ODIR)/talloc.o ../$(ODIR)/molon.lb.o
	$(COMPILE)

.PHONY: check	
.PHONY: check++

check: 
	$(CC) $(CFLAGS) -o out.o *.c

check++: %.c
	g++ $(CFLAGS) -c -o out.o $<
