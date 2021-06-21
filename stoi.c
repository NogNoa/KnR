#include <ctype.h>
#include <stdio.h>
void reverse(char s[]);

// Ritchie, D. and Kernighan, W. (1988) p41

int atoi(char s[])
{ /* atoi: convert s to integer */
int i, n;
n = 0;
for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
	n = 10 * n + (s[i] - '0');
return n;
}

// Ritchie, D. and Kernighan, W. (1988) p59

void KnR_itoa(int n, char s[])
{ /* itoa: convert n to characters in s */
	int i, sign;

	if ((sign = n) < 0) /* record sign */
		n = -n; /* make n positive */
	i = 0;
	do { /* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

// original

int htoi(char s[])
{ /* convert hexadecimal string to integer */
	int i=0,n=0;
	char d;
	if (s[0]=='0' && (s[1]=='x' || s[1]=='X'))
		i = 2;
	for (;s[i] != '\0' ;++i)
	{
		if (isdigit(s[i]))
			d = (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <= 'F')
			d = (s[i] - 'A' + 0xA);
		else if (s[i] >= 'a' && s[i] <= 'f')
			d = (s[i] - 'a' + 0xa);
		else
			break;
		n = 16 * n + d;
	}
	return n;
}

void itoa(int n, char s[])
{ /* itoa: convert n to characters in s */
	int i=0;
	_Bool sign; //1 is negative, 0 is positive;

	if ((sign = (n < 0))) /* record sign */
	{	if (n==-n)
		{	s[i++] = -(n % 10) + '0';
			n /= 10;
		}
		n = -n; /* make n positive */
	}
	do { /* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */
	if (sign)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

short itob(int n, char s[], short b)
{ /* itoa: convert n to characters in s */
	int i=0;
	_Bool sign; //1 is negative, 0 is positive;
	short digit;

	if (b<1 || 36<b)
	{	printf("%d is a bad base",b);
		return 1;
	} 


	if((digit = n % b)<0)
	{	digit = -digit;
		n = -(n/b);
		sign = 1;
	}
	else
		n = n/b;

	if(digit<10)
		s[i++] = digit + '0';
	else
		s[i++] = digit - 10 + 'A';
	
	while ((n /= b) > 0)
	{ /* generate digits in reverse order */
		if((digit = n % b)<10)
			s[i++] = digit + '0';
		else
			s[i++] = digit - 10 + 'A';
	}  /* delete it */
	if (sign)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	return 0;
}

//for some reason at a power of 2 base the minimal negative integer is printed as -0

char lower(char s)
{ /* lower: if it's a capital letter, returns it's minuscule */
	return ((s>'A') && (s<'Z')) ? (s+'a'-'A') : s;
}
