#include "dcl.h"

int main()
{ /* undcl: convert word descriptions to declarations */
	int type, last=0;
	char temp[011*MAXTOKEN];
	/* out is octal 010 times MAXTOKEN, 
	togheter w/ token we have to make room for 011*/ 
	
	while (gettoken() != EOF) 
	{	strcpy(out, token);
		while ((type = gettoken()) != '\n')
		{	if (type == PARENS || type == BRACKETS)
			{	if (last == '*')
				{	sprintf(temp, "(%s)", out);
					strcpy(out, temp);
				}
				strcat(out, token);
			} else if (type == '*') 
			{	sprintf(temp, "*%s", out);
				strcpy(out, temp);
			} else if (type == NAME) 
			{	sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				fprintf(stderr,"invalid input at %s\n", token);
			last =type;
		}
		printf("%s\n",out);
	}
	return 0;
}
