// Ritchie, D. and Kernighan, W. (1988) p110


#include <ctype.h>
#include "dcl.h"

void dcl(void);
void dirdcl(void);
void typedcl(void);

char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
int tokentype; /* type of last token */
_Bool linebreak; /* notice an empty line */

int main(void) 
{ /* convert declaration to words */
	//stdin= fopen("b.txt", "r");
	token[0] = '\0'; /* making sure not to get garbage */
	while ((tokentype = gettoken()) != EOF)  /* 1st token on line */
	{	out[0] = '\0';
		datatype[0] = '\0'; /* forget datatype */
		name[0] = '\0'; /*forget variable name */
		linebreak = 0;
		typedcl(); 
		for (;tokentype == ')' || tokentype == ']'; tokentype=gettoken())
			fprintf(stderr, "error- Found a dangling %c. Have you lost it?\n", tokentype);
		if (tokentype != '\n' && tokentype != EOF)
		{	fprintf(stderr,"syntax error %d %c\n", tokentype, tokentype);
		}
		if (!linebreak)
			printf("%s: %s %s\n\n", name, out, datatype);
	}
	return 0;
}

void dcl(void)
{ /* dcl: parse a declarator */
	int ns=0;
	while ((tokentype = gettoken()) == '*') /* count *'s */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

void argwrite(void)
{
	char ante[MAXTOKEN], post[MAXTOKEN];
	strcat(out, " function taking");
	ante[0]= post[0] = '\0';
	while ((tokentype=gettoken()) != ')')
	{
		if (tokentype == NAME)
		{	strcpy(post, ante);
			strcpy(ante, " ");
			strcat(ante, token);
			strcat(ante, post);
		} else if (tokentype == '*')
		{	strcpy(post, ante);
			strcpy(ante, " pointer to");
			strcat(ante, post);
	    } else if (tokentype == ',')
		{	strcat(out, ante);
			strcat(out, ",");
			ante[0]='\0';
		}
		else 
		{	fprintf(stderr,"error- unrecognised token ");
			if (tokentype < 3)
				fprintf(stderr,"\"%s\"",token);
			else
				fprintf(stderr,"\'%c\'",tokentype);
			fprintf(stderr," in arguments\n");
		}
	}
	strcat(out, ante);
	strcat(out, " and returning");
}

void dirdcl(void)
{ /* dirdcl: parse a direct declarator */
	if (tokentype == '(')  /* ( dcl ) */
	{	dcl();
		if (tokentype != ')')
		{	fprintf(stderr,"error- missing )\n");
			ungettoken(tokentype);
		}
	} else if (tokentype == NAME && !*name) /* variable name */
		strcpy(name, token);
	else if (tokentype == '\n')
		return;
	else
	{	fprintf(stderr,"error- expected name or (dcl)\n");
		ungettoken(tokentype);
	}
	for (_Bool cont=1;cont;)
	{	tokentype=gettoken();
		if (tokentype == PARENS)
			strcat(out, " function returning");
		else if (tokentype == BRACKETS) 
		{	strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
		else if (tokentype == '(')
			argwrite();
		else
			cont = 0;
	}
}

void typewrite(void)
{
	if (!*datatype)
		strcpy(datatype, token);
	else
	{	strcat(datatype, " ");
		strcat(datatype, token);
	}
	if (!strcmp(token, "const") || !strcmp(token,"volatile") || !strcmp(token,"restrict")|| !strcmp(token,"atomic"))
	{	//_atomic with an underscore is not purely alphanumeric and doesn't worth the effort for us 
		tokentype = gettoken();
		if (tokentype == NAME) /* variable name */
			typewrite();
		else
			ungettoken(tokentype);
	}
}

void typedcl(void)
{ 
	if (tokentype == '(')  /* ( dcl ) */
	{	tokentype = gettoken();
		typedcl();
		for (;tokentype == NAME; tokentype = gettoken())
			fprintf(stderr,"error- dangling word \"%s\"\n", token);
		if (tokentype != ')')
		{	fprintf(stderr,"error- missing ) at typedcl\n");
			return;
		}
	} 
	else if (tokentype == NAME) /* variable name */
		typewrite();
	/*else if (tokentype == ')')
	{	fprintf(stderr,"error: looks like those brackets were empty\n");
		return; //just a short circuit
	}*/
	else if (tokentype == '\n')
	{	linebreak = 1;
		return;
	}
	else 
	{	fprintf(stderr,"error- expected type name\n");
		ungettoken(tokentype);
	}
	dcl(); /* parse rest of line */
}




/* type |  *      (    | name   |    )    | () []
   main | dcl<->dirdcl | dirdcl | dirdcl  | dirdcl 
*/
