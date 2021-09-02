#include "dcl.h"

int main()
{ /* undcl: convert word descriptions to declarations */
	int type, last=0;
	char temp[MAXTOKEN];
	while (gettoken() != EOF) 
	{	strcpy(out, token);
		while ((type = gettoken()) != '\n')
		{	if (strlen(out) + strlen(token) + 2 > MAXTOKEN)
				break;
			if (type == PARENS || type == BRACKETS)
			{	if (last == '*')
				{	sprintf(temp, "(%s)", out); //2
					strcpy(out, temp);
				}
				strcat(out, token);
			} else if (type == '*') 
			{	sprintf(temp, "*%s", out); //1
				strcpy(out, temp);
			} else if (type == NAME) 
			{	sprintf(temp, "%s %s", token, out); //token+1
				strcpy(out, temp);
			} else
				fprintf(stderr,"invalid input at %s\n", token);
			last =type;
		}
		printf("%s\n",out);
	}
	return 0;
}
