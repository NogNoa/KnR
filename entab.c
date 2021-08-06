#include "tabbin.h"

struct tabbin arg_prcs(int argc, char *argv[]);

int fndstp (int start, int gap, int *stops, int len, int i);

/* tab-stops of 4-spaces each. */

int entab(int strt, int gap, int *stops, int len)
{
	int i=0, spc=0;
	char c;
	
	while ((c = getchar()) != EOF){
		if (c == ' '){
			++spc;
			int nxtstp = fndstp(strt, gap, stops , 0, i); //nxtstp
			int rmn = (nxtstp - i);
			if (spc > rmn)
			{	putchar('\t');
				i   += rmn;
				spc -= rmn;
			}
		}
		else
		{	i += spc;
			if (i >= MXLIN)
			{	putchar('\n');
				i=spc=0;
			}
			else for (;spc>0;--spc)
				putchar(' ');
			putchar(c);
			++i;
		}
		if (c == '\n')
			i = 0;
	}
	return i;
}

int main(int argc, char *argv[])
{
	int back;
	struct tabbin taby;

	stdin = fopen("a.txt","r");

	if (argc < 2)
	{	int stops[2] = {0,MXLIN};
		back = entab(0, 4, stops, 2);
	}
	else
	{	taby = arg_prcs(argc, argv);
		back = entab(taby.m, taby.n, taby.stops, argc+1);
	}
	return back;
}
