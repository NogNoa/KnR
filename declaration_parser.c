// Ritchie, D. and Kernighan, W. (1988) p110


#include <ctype.h>
#include "dcl.h"

void dcl(int);
void dirdcl(void);
void typedcl(void);

char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
int tokentype; /* type of last token */

int main(void) 
{ /* convert declaration to words */
	//stdin= fopen("b.txt", "r");
	token[0]='\0'; /* making sure not to get garbage */
	while ((tokentype = gettoken()) != EOF)  /* 1st token on line */
	{	out[0] = '\0';
		typedcl(); /* is the datatype */
		dcl(0); /* parse rest of line */
		if (tokentype != '\n' && tokentype != EOF)
			fprintf(stderr,"syntax error %d %c\n", tokentype, tokentype);
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

void dcl(int ns)
{ /* dcl: parse a declarator */
	while ((tokentype = gettoken()) == '*') /* count *'s */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}
	
void dirdcl(void)
{ /* dirdcl: parse a direct declarator */
	if (tokentype == '(')  /* ( dcl ) */
	{	dcl(0);
		if (tokentype != ')')
			fprintf(stderr,"error: missing )\n");
	} else if (tokentype == NAME) /* variable name */
		strcpy(name, token);
	/*else if (tokentype == '\n')
		return;*/
	else
		fprintf(stderr,"error: expected name or (dcl)\n");
	for (_Bool cont=1;cont;)
	{	tokentype=gettoken();
		if (tokentype == PARENS)
			strcat(out, " function returning");
		else if (tokentype == BRACKETS) 
		{	strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
		else
			cont = 0;
	}
}

void typedcl(void)
{ 
	static _Bool cont=1;
	if (tokentype == '(')  /* ( dcl ) */
	{	while ((tokentype = gettoken()) != ')' && cont)
			typedcl();
		if (tokentype != ')')
			fprintf(stderr,"error: missing ) at typedcl\n");
	} 
	else if (tokentype == NAME) /* variable name */
	{	strcpy(datatype, token);
		cont=0;
	}
	else if (tokentype == '*')
		dcl(1);
	/*else if (tokentype == '\n')
		return;*/
	else
		fprintf(stderr,"error: expected typename\n");
}



/* type |  *      (    | name   |    )    | () []
   main | dcl<->dirdcl | dirdcl | dirdcl  | dirdcl 
*/
