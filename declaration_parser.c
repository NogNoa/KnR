// Ritchie, D. and Kernighan, W. (1988) p110


#include <ctype.h>
#include "dcl.h"

void dcl(void);
void dirdcl(void);

int tokentype; /* type of last token */
char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */


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

	if (tokentype == '(')  /* ( dcl ) */
	{	dcl();
		if (tokentype != ')')
			printf("error: missing )\n");
	} else if (tokentype == NAME) /* variable name */
		strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");
	for (_Bool cont=1;cont;type=gettoken())
	{	if (type == PARENS)
			strcat(out, " function returning");
		else if (type == BRACKETS) 
		{	strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
		else
			cont = 0;
	}
}
