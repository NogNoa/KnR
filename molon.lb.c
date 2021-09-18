// Ritchie, D. and Kernighan, W. (1988) p86
#ifndef printf
	#include <stdio.h>
#endif
#ifndef isdigit
	#include <ctype.h>
#endif

static int getch(void);
static void ungetch(int);

int getint(int *pn)
{   /* getint: get next integer from input into *pn */
	signed char c, s=0, sign;
	while (isspace(c = getch())) /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{	s=c;
		c = getch();
	}
	if (!isdigit(c))
	{	if (c!= EOF)
			ungetch(c);
		if (s)
			ungetch(s);
		return 0;
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

//original

int getfloat(double *pn)
{   /* getfloat: get next float from input into *pn */
	signed char c, s=0, sign;
	int i=0;
	while (isspace(c = getch())) /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c!= '.') {
		ungetch(c); /* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{	s=c;
		c = getch();
		if (!isdigit(c))
		{	if (c!= EOF)
				ungetch(c);
			if (s)
				ungetch(s);
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	if (c == '.')
	{	c = getch();
		if (!isdigit(c))
		{	if (c!= EOF)
				ungetch(c);
			if (s)
				ungetch('.');
			return 0;
		}
		for (;isdigit(c); c = getch(), i++)
			*pn = 10 * *pn + (c - '0');
	}
	for (int j=0;j<i;j++)
		*pn /= 10;
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

// Ritchie, D. and Kernighan, W. (1988) p69

#include <string.h> /* for strlen() */
#define BUFSIZE 100
static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */

static int getch(void) 
{	/* get a (possibly pushed-back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}

static void ungetch(int c) 
{	/* push character back on input */
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else if (c != EOF)
		buf[bufp++] = c;
}

//original

void unget(char s[])
{
	int l;

	if (bufp + (l=strlen(s)) > BUFSIZE )
		printf("unget: too long string %s\n",s);
	else
		for (int i=0;i<l;++i)
			buf[bufp++] = s[i];
}

// Ritchie, D. and Kernighan, W. (1988) p91

#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
		allocp += n;
		return allocp - n; /* old p */
	} else /* not enough room */
		return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
	allocp = p;
}

#include "dcl.h"

// Ritchie, D. and Kernighan, W. (1988) p111

int gettoken(void) 
{ /* return next token */
	int type, getch(void);
	void ungetch(int);
	char *p = token, c;
	while (isspace(c = getch()) && c != '\n')
		;
	if (c == '(') 
	{	if ((c = getch()) == ')') 
		{	strcpy(token, "()");
			type = PARENS;
		} else 
		{	ungetch(c);
			type = '(';
		}
	} else if (c == '[') 
	{	for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		type = BRACKETS;
	} else if (isalpha(c)) 
	{	for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		type = NAME;
	} else
		type = c;
	return type;
}

void ungettoken(int tokentype)
{	
	ungetch(tokentype);
}

/*if tokentype that is either NAME, PARENS, BRACKETS it pushed back on the stack 
than with gettoken it will be pulled again as the type, 
and the token is supposed to still be there since the stack is very shallow
(only used for one token + a charecter after reading a new string token)
*/

// Ritchie, D. and Kernighan, W. (1988) p121

int getword(char *word, int lim)
{ /* getword: get next word or character from input */
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (isalpha(c)) 
	{	for ( ; --lim > 0; w++)
			if (!isalnum(*w = getch()) && *w != '_') 
			{	ungetch(*w);
				break;
			}
	}
	*w = '\0';
	return c;
}

//original

char ig_getword(char *word, int lim)
{ /* ig_getword: get next word or character from input 
	 ignores preprocessor, strings constants and comments*/
	char *w = word, c;

	while (isspace(c = getch()))
		;
	for (;"ever";c = getch())
	{	if (c == '/')
		{	if ((c = getch()) == '/')
				while ((c = getch()) != '\n' && c != EOF)
					;
			else if (c == '*')
				while (!((c = getch()) == '*' && (c = getch()) == '/') && c != EOF)
					;	
		}
		else if (c == '#')
			while ((c = getch()) != '\n' && c != EOF)
				;
		else if (c == '\"')
			while ((c = getch()) != '\"' && c != EOF)
				;
		else
		{	break;
		}
	}
	if (c != EOF)
		*w++ = c;
	if (isalpha(c)) 
	{	for ( ; --lim > 0; w++)
			if (!isalnum(*w = getch()) && *w != '_') 
			{	ungetch(*w);
				break;
			}
	}
	*w = '\0';
	return c;
}

int lngetword(char *word, int lim)
{ /* getword: get next word or character from input */
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	while (isspace(c = getch()) && !(c == '\n'))
		;
	if (c != EOF)
		*w++ = c;
	if (isalpha(c)) 
	{	for ( ; --lim > 0; w++)
			if (!isalnum(*w = getch()) && *w != '_') 
			{	ungetch(*w);
				break;
			}
	}
	*w = '\0';
	return c;
}

char get_directive(char *direct, int lim)
{
	char c='\n';
	*direct='\0';
	while (!(*direct) && c != EOF)
	{	if (c == '\n' && (c=getch()) == '#')
		{	while ((c=getch()) != '\n' && --lim > 0)
				*direct++ = c;
			*direct = '\n';
		} 
		else
			c=getch();
	}
	return c;
	/* success: if *direct != 0 */
}
