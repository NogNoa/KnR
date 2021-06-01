// Ritchie, D. and Kernighan, W. (1988) p45

unsigned KnR_getbits(unsigned x, int p, int n)
{ /* getbits: get n bits from position p */
	return (x >> (p+1-n)) & ~(~0 << n);
}

// original

# include <limits.h>
# ifndef UINT_WIDTH
#  define UINT_WIDTH 32
# endif

unsigned getbits(unsigned x, int p, int n)
{ /* getbits: get n bits from position p, sansibely, that is from right to left */
	return ((x >> p) & ~(~0 << n));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{ /* setbits: return x but with n bits from position p taken from y */
	return (x >> (p+n) << (p+n)) | (getbits(y,p,n) << p) | getbits(x,0,p);
}

unsigned invert(unsigned x, int p, int n)
{ /* invert: switch the values of n bits from position p */
	return x ^ ((1 << n) -1) << p;
}

unsigned rightrot(unsigned x, int n)
{
	return (x << (UINT_WIDTH - n)) | (x >> n);
}

int bitcount(int x)
{ /* bitcount: count 1 bits in x */
	int b = 0;
	
	while (x != 0){
		x&= (x-1);
		b++;
	}
	return b;
}
