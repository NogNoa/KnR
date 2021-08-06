#include <ctype.h>
#include "tabbin.h"

struct tabbin arg_prcs(int argc, char *argv[]);
int fndstp (int start, int gap, int *stops, int len, int i);

int detab(int start, int gap, int *stops, int len)
{
	int i=0;
	char c;
	
	while ((c = getchar()) != EOF)
	{	if (isspace(c) && i >= MXLIN)
			{	putchar('\n');
				i=0;
			}
		else if (c == '\t')
		{	int stop = fndstp(start, gap, stops, len, i);
			for(;i < stop;i++) 
				putchar(' ');
			if (i>=MXLIN)
			{	putchar('\n');
				i = 0;
			}
		}
		else if (c == '\n')
		{	putchar(c);
			i = 0;
		}
		else
		{	putchar(c);
			++i;
		}
	}
	return i;
}

int main(int argc, char *argv[])
{
	int back;
	struct tabbin taby;
	//stdin = fopen("detab.c", "r");
	
	if (argc < 2)
	{	/* tab-stops of 4-spaces each. */
		int stops[2]={0,MXLIN};
		back = detab(0,4,stops,2);
	}
	else 
	{	taby = arg_prcs(argc, argv);
		back = detab(taby.m,taby.n,taby.stops, argc+1);
	}
	return back;
}

/* todo: make combined mathod that just create 1 list of stops from both speicel and regular arguments */
