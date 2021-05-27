// Ritchie, D. and Kernighan, W. (1988) p45

unsigned KnR_getbits(unsigned x, int p, int n)
{ /* getbits: get n bits from position p */
	return (x >> (p+1-n)) & ~(~0 << n);
}

// original

unsigned getbits(unsigned x, int p, int n)
{ /* getbits: get n bits from position p, sansibely, that is from right to left */
	return ((x >> p) & ~(~0 << n));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x >> (p+n) << (p+n)) | getbits(x,0,p) | (getbits(y,p,n) << p);
}
