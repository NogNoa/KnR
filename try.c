#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(int argc, char *argv[])
{
	printf("%x\n",setbits(0xa6, 2, 3, 0xfc));
}
