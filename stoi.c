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
	_Bool sign = (n < 0); //1 is negative, 0 is positive;
	unsigned m;
	

	if (n==-n)
		m = ((unsigned)-(n+1))+1;
	else
	{	m = n;
		if (sign)
			m = -m;
	}

	do { /* generate digits in reverse order */
		s[i++] = m % 10 + '0'; /* get next digit */
	} while ((m /= 10) > 0); /* delete it */
	if (sign)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

short itob(int n, char s[], short b)
{ /* itoa: convert n to characters in s */
	int i=0;
	_Bool sign = (n < 0); //1 is negative, 0 is positive;
	short digit;
	unsigned m;

	if (b<2 || 36<b)
	{	printf("%d is a bad base. Please use one between 2 and 36.\n",b);
		s[0]='\0';
		return 1;
	}

	if (n==-n)
		m = ((unsigned)-(n+1))+1;
	else
	{	m = n;
		if (sign)
			m = -m;
	}

	do
	{ /* generate digits in reverse order */
		digit = m % b;
		s[i++] = digit + ((digit<10)? '0' :'A' - 10);
	}while ((m /= b) > 0);

	if (sign)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	return 0;
}

//now it prints the minimal negative correctly even with power of 2 base
//but prints zero as -0 which is technicaly not wrong

char lower(char s)
{ /* lower: if it's a capital letter, returns it's minuscule */
	return ((s>'A') && (s<'Z')) ? (s+'a'-'A') : s;
}
