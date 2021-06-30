// Ritchie, D. and Kernighan, W. (1988) p69
//freely edited

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define ANS '1' /* signal for the last output */
#define CMD '2' /* signal that a alphabetic string was found */
_Bool compare(char s[], char sh[]);
int getop(char []);
void getcmd(char s[]);
void push(double);
double pop(_Bool idntt);
double fmod(double dend,double sor);
double ans=0;

int main()
{	/* reverse Polish calculator */
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
			break;
			case ANS:
				push(ans);
			break;
			case CMD:
				getcmd(s);
			break;
			case '+':
				push(pop(0) + pop(0));
			break;
			case '*':
				push(pop(1) * pop(1));
			break;
			case '-':
				op2 = pop(0);
				push(pop(0) - op2);
			break;
			case '/':
				op2 = pop(1);
				if (op2 != 0.0)
					push(pop(1) / op2);
				else
					printf("error: zero divisor\n");
			break;
			case '%':
				op2 = pop(1);
				if (op2 != 0)
					push(fmod(pop(0),op2));
				else
					printf("error: zero divisor\n");
			break;		
			case '=':
				printf("\t%.8g\n", pop(0));
			break;
			default:
				printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}


#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */


void push(double f)
{	/* push: push f onto value stack */
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}


double pop(_Bool idntt)
{	/* pop: pop and return top value from stack */
	if (sp > 0)
		return val[--sp];
	else {
		return (double) idntt; /* element of identity: 0.0 for +-, 1.0 for */
	}
}


#include <ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{	/* getop: get next character or numeric operand */
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t' || c == '\n')
		;
	s[1] = '\0';
	if (c == '_')  /* collect the last-answer charecter */
		return ANS;
	if ('a'< c && c < 'z')
		return CMD;
	if (!isdigit(c) && c != '.')	
		return c; /* not a number */
	s[1]=' ';i = 2;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	if ((c = getch()) == '-')
		s[1] = '-';
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

void fifo_print_all(void);
void show(void);
void duplicate(void);
void swap_top(void);
void stack_clear(void);

void getcmd(char s[])
{
	int i;
	char c;

	for (i=1;(s[i] = c = getch()) != ' ' && c != '\t' && c!= '\n';++i)
		;
	s[i+1]='\0';
	if (compare(s,"showall"))
		fifo_print_all();
	else if (compare(s,"show"))
		show();
	else if (compare(s,"dupp"))
		duplicate();
	else if (compare(s,"swap"))
		swap_top();
	else if (compare (s, "clear"))
		stack_clear();
	else
		printf("error: literal %s\n", s);
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */


int getch(void) 
{	/* get a (possibly pushed-back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c) 
{	/* push character back on input */
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void fifo_print_all(void)
{
	putchar('\t');
	for (int i=0;i<sp;++i)
		printf("%.8g ",(ans =val[i]));
	putchar('\n');
}

void show(void)
{
	;
}
void duplicate(void)
	{;}
void swap_top(void)
	{;}
void stack_clear(void)
	{;}

double fmod(double dend,double sor)
{
	return dend - ((int) ( dend / sor)) * sor;
}

/* 
how to input negative numbers
 3 - 4 == 3 4 -
-3 + 4 == 3 - 4 +
-3 - 4 == 3 - 4 -
-3 * 4 == 3 - 4 *
-3 * -4 == 3 - 0 4 - * (could be better)
 3 * -4 == 4 - * 3 == 3 0 4 - * (could be better)
(-3)/4 == 3 - 4 /
3/(-4) == 3 0 4 - / (could be better)
(-3)/(-4) == 3 - 0 4 - / (could be better)
-(3/4) == 3 4 / - 

strictly unary -

 3 - 4 == 3 4 - +
-3 + 4 == 3 - 4 +
-3 - 4 == 3 - 4 - +
-3 * 4 == 3 - 4 *
-3 * -4 == 3 - 4 - *
 3 * -4 == 3 4 - *
(-3)/4 == 3 - 4 /
3/(-4) == 3 4 - /
(-3)/(-4) == 3 - 4 - /
-(3/4) == 3 4 / -

both negative constants and binary subtraction 
(only assumed most idiomatic option)

 3 - 4 == 3 4 - 
-3 + 4 == -3 4 +
-3 - 4 == -3 4 - 
-3 * 4 == -3 4 *
-3 * -4 == -3 -4 *
 3 * -4 == 3 -4 *
(-3)/4 == -3 4 /
3/(-4) == 3 -4 /
(-3)/(-4) == -3 -4 /
-(3/4) == 0 3 4 / -

both negative constants and binary subtraction (strictly suffixial)
(only assumed most idiomatic option)

				 ;actual answer;space change meaning to; no space 
 3 - 4 == 3 4 -  ;-1;;3 -4
-3 + 4 == 3- 4 + ;1;1
-3 - 4 == 3- 4 - ;-7;-7;-3 -4
-3 * 4 == 3- 4 * ;-12;-12
-3 * -4 == 3- 4- * ;12;-7 
 3 * -4 == 3 4- * ;-12;-1
(-3)/4 == 3- 4 / ;-.75;-.75
3/(-4) == 3 4- / ;-.75;-1
(-3)/(-4) == 3- 4- / ;.75;1/-7
-(3/4) == 0 3 4 / - ;-.75;;

*/
/*
(a+b) % (c+d)= (e+f)
(a+b) // (c+d) = g
g*(c+d) + (e+f) = (a+b)
(a+b) - g(c+d) = (e+f)

floor (7.2 / 3.5) = 2
7.2 % 3.5 = .2
7 % 3 = 1
7.2 - 3.5 = 3.7
7.2 - 3.5 * 2=.2 

*/
