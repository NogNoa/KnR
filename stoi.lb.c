/* gcc with control_flow.lib.c */

#include <ctype.h>
#ifndef printf
	#include <stdio.h>
#endif
#include <string.h>
#ifndef malloc 
	#include <stdlib.h>
#endif

char *reverse(char *); //from control_flow.lb.c

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
	reverse(s); //defined in control_flow.c
}

// Ritchie, D. and Kernighan, W. (1988) p65

double KnR_atof(char s[])
{	/* atof: convert string s to double */
	double val, power;
	int i, sign;
	
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) 
	{	val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;
}


// original

int alt_atoi(char *s)
{ /* ptr_atoi: convert s to integer */
int n;
n = 0;
for (; *s >= '0' && *s <= '9'; s++)
	n = 10 * n + (*s - '0');
return n;
}

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
{ /* itoa: convert n to string in s */
	int i=0;
	_Bool sign = (n < 0); //1 is negative, 0 is positive;
	unsigned m;
	

	if (sign)
		m = ((unsigned)-(n+1))+1;
	else
		m = n;

	do { /* generate digits in reverse order */
		s[i++] = m % 10 + '0'; /* get next digit */
	} while ((m /= 10) > 0); /* delete it */
	if (sign)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


char * itob(int n, short b)
{ /* itoa: convert n to base b string in s */
	_Bool sign = (n < 0); //1 is negative, 0 is positive;
	short digit;
	unsigned m;
	char *s=malloc(1024);

	if (b<2 || 36<b)
	{	printf("%d is a bad base. Please use one between 2 and 36.\n",b);
		*s='\0';
		return s;
	}

	if (sign)
		m = ((unsigned)-(n+1))+1;
	else
		m = n;

	do
	{ /* generate digits in reverse order */
		digit = m % b;
		*s++ = digit + ((digit<10)? '0' :'A' - 10);
	}while ((m /= b) > 0);

	if (sign)
		*s++ = '-';
	*s = '\0';
	reverse(s);
	return s;
}


void fill_itoa(int n, char s[], int fill)
{ /* itoa: convert n to string od length fill in s*/
	int i=0;
	_Bool sign = (n < 0); //1 is negative, 0 is positive;
	unsigned m;
	
	if (sign)
		m = ((unsigned)-(n+1))+1;
	else
		m = n;

	do { /* generate digits in reverse order */
		s[i++] = m % 10 + '0'; /* get next digit */
	} while ((m /= 10) > 0); /* delete it */
	while(i<fill)
		s[i++]='0';
	if (sign)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


void rcrs_itoa(int n, char s[])
{ /* itoa: convert n to string in s using recursion */
	static int i=0;
	int m;

	if (n<0) 
	{	s[i++]='-';
		n = -n;
	}
	if ((m=n/10) > 0)
		rcrs_itoa(m,s);
	s[i++] = n % 10 + '0';
	s[i] = '\0';
}



char lower(char s)
{ /* lower: if it's a capital letter, returns it's minuscule */
	return ((s>'A') && (s<'Z')) ? (s+'a'-'A') : s;
}

double tentothe(double power, int sign)
{ 	// return 10 ^ (sign * power)
	double back=1;

	if (sign > 0)
		for (;power>0;--power)
			back *= 10;
	else
		for (;power>0;--power)
			back /= 10;
	return back;
}

double sci_atof(char s[])
{	/* atof: convert string s to double */
	double val, tens=1.;
	int i, sign, pow_sign=1, power=0;
	
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
	{	i++;
		for (; isdigit(s[i]); i++) 
		{	val = 10.0 * val + (s[i] - '0');
			tens /= 10;
		}
	}

	if (s[i] == 'e' || s[i] == 'E')
			i++;
	
	if (s[i] == '-')
	{	pow_sign=-1;
		i++;
	}
	for (; isdigit(s[i]); i++) 
	{	power = 10.0 * power + (s[i] - '0');
	}
	tens *= tentothe(power, pow_sign);
	return sign * val * tens;
}

int btoi(char *s,int b)
{ /* ptr_atoi: convert s to integer */
	int n=0;
	char digit;
	const char basi[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (b < 2 ||strlen(basi) < b)
	{	printf("%d is a bad base. Please use one between 2 and 36.\n",b);
		return 0;
	}
	while ((digit=strchr(basi,*s++)-basi) >= 0 && digit <= b)
		n = b * n + digit;	
	return n;
}

