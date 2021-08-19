// Ritchie, D. and Kernighan, W. (1988) p110


#include <ctype.h>
#include "dcl.h"

void dcl(void);
void dirdcl(void);

char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
int tokentype; /* type of last token */


int main() 
{ /* convert declaration to words */
	//stdin= fopen("b.txt", "r");
	token[0]='\0'; /* making sure not to get garbage */
	while ((tokentype = gettoken()) != EOF)  /* 1st token on line */
	{	strcpy(datatype, token); /* is the datatype */
		out[0] = '\0';
		dcl(); /* parse rest of line */
		if (tokentype != '\n' && tokentype != EOF)
			fprintf(stderr,"syntax error %d\n",tokentype);
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

void dcl(void)
{ /* dcl: parse a declarator */
	int ns;

	for (ns = 0; (tokentype = gettoken()) == '*'; ) /* count *'s */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}
	
void dirdcl(void)
{ /* dirdcl: parse a direct declarator */
	if (tokentype == '(')  /* ( dcl ) */
	{	dcl();
		if (tokentype != ')')
			fprintf(stderr,"error: missing )\n");
	} else if (tokentype == NAME) /* variable name */
		strcpy(name, token);
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


/* type |  *      (    | name   |    )    | () []
   main | dcl<->dirdcl | dirdcl | dirdcl  | dirdcl 
*/
