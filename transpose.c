#include <ctype.h>
#include "KnR_getline.h"

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
			if (c=='\0')
				dead[lin]=1;
			if (dead[lin] || isspace(c))
				putchar(' ');
			else
				putchar(c);
		}
	putchar('\n');
	}
}

int mxlen=0;

int main()
{
	int many_line;

	many_line = linearise();
	expose(lini, many_line, mxlen);

	return 0;
}
