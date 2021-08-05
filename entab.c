#include "tabbin.h"

struct tabbin arg_prcs(int argc, char *argv[]);

/* tab-stops of 4-spaces each. */

int entab(int gap)
{
	int i=0, spc=0;
	char c;
	
	while ((c = getchar()) != EOF){
		if (c == ' '){
			++spc;
			int rmn;
			if (spc >= (rmn = (gap - i % gap)))
			{	putchar('\t');
				spc -= rmn;
				i = 0;
			}
		}
		else if (c == '\t')
		{	putchar('\t');
			i = 0;
		}
		else
		{	i += spc;
			for (;--spc>0;)
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

	if (argc < 2)
	{	
		back = entab(4);
	}
	else
	{	taby = arg_prcs(argc, argv);
		back = entab(taby.n);
	}
	return back;
}
