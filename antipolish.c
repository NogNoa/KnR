// Ritchie, D. and Kernighan, W. (1988) p69

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);

main()
{	/* reverse Polish calculator */
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
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
			case '\n':
				printf("\t%.8g\n", pop());
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
/* push: push f onto value stack */

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(_bool idntt)
{	/* pop: pop and return top value from stack */
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return (float) idntt; //0 for +,- 1 for *,/
	}
}

#include <ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{	/* getop: get next character or numeric operand */
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
	;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
	return c; /* not a number */
	i = 0;
	if (isdigit(c)) /* collect integer part */
	while (isdigit(s[++i] = c = getch()))
	;
	if (c == '.') /* collect fraction part */
	71
	while (isdigit(s[++i] = c = getch()))
	;
	s[i] = '\0';
	if (c != EOF)
	ungetch(c);
	return NUMBER;
}