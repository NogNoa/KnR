CFLAGS=-Wall -g

clean:
	rm -f word_histogram
all:
	gcc -Wall -g word_histogram.c -o word_histogram.elf
