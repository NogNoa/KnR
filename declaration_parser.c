// Ritchie, D. and Kernighan, W. (1988) p110

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXTOKEN 0200
enum { NAME, PARENS, BRACKETS };
void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype; /* type of last token */
char token[MAXTOKEN]; /* last token string */
char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[02000];

int main() 
{ /* convert declaration to words */
	while (gettoken() != EOF) { /* 1st token on line */
		strcpy(datatype, token); /* is the datatype */
		out[0] = '\0';
		dcl(); /* parse rest of line */
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

void dcl(void)
{ /* dcl: parse a declarator */
	int ns;

	for (ns = 0; gettoken() == '*'; ) /* count *'s */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}
	
void dirdcl(void)
{ /* dirdcl: parse a direct declarator */
	int type;

	if (tokentype == '(') { /* ( dcl ) */
		dcl();
		if (tokentype != ')')
			printf("error: missing )\n");
	} else if (tokentype == NAME) /* variable name */
		strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");
	for (_Bool cont=1;cont;type=gettoken()){
		if (type == PARENS)
			strcat(out, " function returning");
		else if (type == BRACKETS) {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
		else
			cont = 0;
	}
}

int gettoken(void) 
{ /* return next token */
	int c, getch(void);
	void ungetch(int);
	char *p = token;
	
	while ((c = getch()) == ' ' || c == '\t')
	;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}
