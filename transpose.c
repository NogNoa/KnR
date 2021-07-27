#include <stdlib.h>
#include <string.h>
#include "KnR_getline.h"
#define MAX 0x1024

/*
Text is nline lines, each killed by /0.
so we somehow also has to follow which lines are dead. this is beyond me.
15.6.21 still not prepered
*/


void expose(char * lini[],int  nline, int mxlen)
{
	char c;
	_Bool dead[nline];

	for (int i=0;i++<nline;) {dead[i]=0;}

	for (int i=0; i < mxlen; ++i)
	{	for (int lin=0;lin<nline ;++lin)
		{	c=lini[lin][i];
			if (dead[lin] && c == '\t')
				putchar(' ');
			else
				putchar(c);
			if (c=='\0')
				dead[lin]=1;
		}
	putchar('\n');
	}
}


int mxlen = 0;
char * lini[MAX];

int linearise(void)
{
	char line[MAX],*p;
	int nline,len = 0;

	for (nline=0; (len = KnR_getline(line, MAX)); ++nline)
	{	if (nline >= MAX || (p=malloc(len)) == NULL)
			return -1;
		if (line[len-1]== '\n')
			line[--len] = '\0';
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
	expose(lini, many_line, mxlen);

	return 0;
}
