CC = gcc
CFLAGS = -Wall -g
DEPS = tabbin.h
ODIR = obj
_OBJ = 
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))
OBJPILE = $(CC) $(CFLAGS) -c -o $@     $<
COMPILE = $(CC) $(CFLAGS)    -o $@.elf $^

try: $(ODIR)/try.o $(ODIR)/istable.lb.o 
	$(COMPILE) 
$(ODIR)/try.o: istable.lb.h

detab: $(ODIR)/entab.o $(ODIR)/tabbin.lb.o
	$(COMPILE)

entab: $(ODIR)/entab.o $(ODIR)/tabbin.lb.o
	$(COMPILE)

dcl: $(ODIR)/declaration_parser.o $(ODIR)/molon.lb.o
	$(COMPILE)
$(ODIR)/declaration_parser.o: dcl.h

undcl:  $(ODIR)/undcl.o $(ODIR)/molon.lb.o
	$(COMPILE)
$(ODIR)/undcl.o: dcl.h

defproc:  $(ODIR)/define_processor.o $(ODIR)/molon.lb.o $(ODIR)/add_remove-string.lb.o $(ODIR)/table_lookup.lb.o
	$(COMPILE)

find: $(ODIR)/find.o $(ODIR)/file_ops.lb.o
	$(COMPILE)

file_print: $(ODIR)/file_print.o $(ODIR)/file_ops.lb.o
	$(COMPILE)

cat: $(ODIR)/cat.o $(ODIR)/unix.lb.o
	$(COMPILE)
$(ODIR)/cat.o: unix.lb.h

$(ODIR)/%.o: %.c
	 $(OBJPILE)

.PHONY: check
.PHONY: check++

check: 
	$(CC) -Wall -pedantic -o out.o *.c

check++: %.c
	g++ -Wall -pedantic -c -o out.o $<

.PHONY: cleanex
.PHONY: cleanob
.PHONY: cleanall

cleanex:
	rm *.exe *.elf *.ilk *.pdb

cleanob:
	rm $(ODIR)/*.o *.obj

cleanall:
	cleanex  cleanob
