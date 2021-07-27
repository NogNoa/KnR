#include <stdlib.h>
#include <string.h>
#include "KnR_getline.h"
#define MAX 0x1024

/*
Text is nline lines, each killed by /0.
so we somehow also has to follow which lines are dead. this is beyond me.
15.6.21 still not prepered
*/

/*
void expose(char * lini[],int  nline)
{
	char line[MAX];

	do{
		for (int i=0; i <= nline; ++i)
		{	for (int j=0; 0;)
				;
		}

	}while (0);
}
*/

int mxlen = 0;
char * lini[MAX];

int linearise(void)
{
	char line[MAX],*p;
	int nline,len = 0;

	for (nline=0; (len = KnR_getline(line, MAX)); ++i)
	{	if (nline >= MAX || (p=malloc(len)) == NULL)
			return -1;
		strcpy(p,line);
		lini[nline] = p;
		if (len>mxlen)
			mxlen=len;
	}
	return nline;
}


int main()
{
	int many_line;

	many_line = linearise();
	for (int i;i<52;++i)
		printf("%s\n", lini[i]);

	return 0;
}
