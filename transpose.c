#include <ctype.h>
#include "KnR_getline.h"

/*
Text is nline lines, each killed by /0.
so we somehow also has to follow which lines are dead. this is beyond me.
15.6.21 still not prepered
*/


void expose(page pg)
{
	char c;
	_Bool dead[pg.nline];

	for (int i=0;i++ < pg.nline;) {dead[i]=0;}

	for (int i=0; i < pg.mxlen; ++i)
	{	for (int lin=0;lin < pg.nline ;++lin)
		{	c=pg.lini[lin][i];
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

int main()
{
	stdin = fopen("transpose.c","r");

	page pg = linearise();
	expose(pg);

	return 0;
}
