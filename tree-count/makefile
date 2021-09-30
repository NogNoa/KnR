CC = gcc
CFLAGS = -Wall
DEPS = tree_count.h
ODIR = obj
_OBJ = addtree talloc tree_print
OBJ = $(patsubst %, $(ODIR)/%.o, $(_OBJ))
OBJPILE = $(CC) $(CFLAGS) -c -o $@     $<
COMPILE = $(CC) $(CFLAGS)    -o $@.elf $^ 
.DEFAULT_GOAL = tree_count

$(ODIR)/%.o: %.c $(DEPS)
	 $(OBJPILE)

../$(ODIR)/molon.lb.o: ../molon.lb.c
	 $(OBJPILE)

tree_count: $(ODIR)/tree_count.o $(OBJ) ../$(ODIR)/molon.lb.o
	$(COMPILE)

cvar: $(ODIR)/cvar_count.o $(OBJ) ../$(ODIR)/molon.lb.o
	$(COMPILE)

cross: $(ODIR)/cross_count.o $(OBJ) ../$(ODIR)/molon.lb.o
	$(COMPILE)

freq: $(ODIR)/freq_count.o $(OBJ) ../$(ODIR)/molon.lb.o
	$(COMPILE)

.PHONY: check	
.PHONY: check++

check: 
	$(CC) $(CFLAGS) -o out.o *.c

check++: %.c
	g++ $(CFLAGS) -c -o out.o $<
