// Ritchie, D. and Kernighan, W. (1988) p69
//freely edited

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h> /* for sin, exp, pow, etc. */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define CMD '1' /* signal that a alphabetic string was found */
#define VAR '2' /* signal for the variable management routine */
int getop(char []);
void getcmd(char s[]);
void getvar(char s[]);
void fifo_print_all(void);
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
			case '_':
				push(ans);
			break;
			case CMD:
				getcmd(s);
			break;
			case VAR:
				getvar(s);
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
				printf("\t%.8g\n", (ans=pop(0)));
			break;
			default:
				printf("error: unknown command %s\n", s);
			break;
		}
	}
	fifo_print_all();
	return 0;
}


inline double fmod(double dend,double sor)
{
	return dend - floor( dend / sor) * sor;
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

void fifo_print_all(void)
{
	putchar('\t');
	for (int i=0;i<sp;++i)
		printf("%.8g ",val[i]);
	ans=val[sp-1];
	putchar('\n');
}

inline void show(void)
{
	printf("%.8g ",(ans=val[sp-1]));
}

void duplicate(void)
{
	for (int i=0;i<sp;++i)
		val[sp+i] = val[i];
	sp*= 2;
}

void swap_top(void)
{
	double temp;
	temp = val[sp-1];
	val[sp-1] = val[sp-2];
	val[sp-2] = temp;
}

inline void stack_clear(void)
{
	sp=0;
}


#include <ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{	/* getop: get next character or numeric operand */
	int i;
	char c;
	
	s[0]=' ';
	while ((s[1] = c = getch()) == ' ' || c == '\t' || c == '\n')
		;
	s[2] = '\0';
	if ('a'< c && c < 'z')
		return CMD;
	if ('A' <= c && c <= 'Z')
		return VAR;
	if (!isdigit(c) && c != '.')	
		return c; /* not a number */
	i = 1;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '-')
		s[0] = '-';
	else if (c != EOF)
		ungetch(c);
	s[i] = '\0';
	return NUMBER;
}

_Bool var_able[26];
float var[26]={0};

void getvar(char s[])
{
	char c,v=s[1];

	while ((c = getch()) == ' ' || c == '\t' || c == '\n')
		;
	if (c == '$')
	{	var[v-'A']=pop(0);
		var_able[v-'A']=1;
	}
	else 
	{	if (var_able[v-'A'])
			push(var[v-'A']);
		else
			printf("error: undefined variable %c\n",v);
		if (c != EOF)
			ungetch(c);
	}
}



_Bool compare(char s[], char sh[]); /* from add_remove-string.c */
void show(void);
void stack_clear(void);

void getcmd(char s[])
{
	int i;
	char c;
	double op2;

	for (i=2;(s[i] = c = getch()) != ' ' && c != '\t' && c!= '\n';++i)
		;
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
	else if (compare(s, "sin"))
		push(sin(pop(0)));
	else if (compare(s, "exp"))
		push(exp(pop(1)));
	else if (compare(s, "cos"))
		push(cos(pop(0)));
	else if (compare(s, "pow"))
	{	op2=pop(1);
		push(pow(pop(1),op2));
	}
	else if (compare(s, "log"))
		push(log(pop(1)));
	else if (compare(s, "sqrt"))
		push(sqrt(pop(1)));
	else if (compare(s, "abs"))
		push(abs(pop(0)));
	else
		printf("error: unknown literal %s\n", s);
	s[i+1]='\0';
	if (c != EOF)
		ungetch(c);
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
