#include <stdio.h>

struct tabbin arg_prcs(int argc, char *argv[]);

/* tab-stops of 4-spaces each. */

int entab(int gap)
{
	int i=0, s=0;
	char c;
	
	while ((c = getchar()) != EOF){
		if (c == ' '){
			++s;
			int r;
			if (s >= (r = (gap - i % gap))){
				putchar('\t');
				s -= r;
				i = 0;
			}
		}
		else if (c == '\t'){
			putchar('\t');
			i = 0;
		}
		else{
			i += s;
			for (;s>0;--s)
				putchar(' ');
			putchar(c);
			++i;
		}
		if (c == '\n')
			i = 0;
	}
	return i;
}

struct tabbin 
{	int n,m;
	int *stops;
};

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
