#include <stdio.h>
#include <stdlib.h>
#define MXLIN 72 /* max line length*/

int detab_reg(int gap)
{
	int i=0;
	char c;
	
	while ((c = getchar()) != EOF){
		if (c == '\t')
			for(int j = i % gap; j < gap && i <= MXLIN; ++j, ++i)
				putchar(' ');
		else if (c == '\n'){
			putchar(c);
			i = 0;
		}
		else
		{	if (c == ' ' && i > MXLIN)
			{	putchar('\n');
				i=0;
			}
			putchar(c);
			++i;
		}
	}
	return i;
}

int detab(int len, int *stops)
{
	int i=0;
	char c;
	
	while ((c = getchar()) != EOF){
		if (c == '\t')
		{	_Bool cnt=1;
			while (cnt)
			{	putchar(' ');
				 ++i;
				for (int*p=stops;p<stops+len;++p)
					if (*p==i || i > MXLIN)
						cnt=0;
			}
			if (i > MXLIN)
			{	putchar('\n');
				i=0;
			}
		}
		else if (c == '\n'){
			putchar(c);
			i = 0;
		}
		else if (c == ' ' && i > MXLIN)
			{	putchar('\n');
				i=0;
			}
		else
		{	putchar(c);
			++i;
		}
	}
	return i;	

}

int main(int argc, char *argv)
{
	int back;
	//stdin = fopen("detab.c", "r");
	
	if (argc < 2)
		/* tab-stops of 4-spaces each. */
		back = detab_reg(4);
	else 
	{	int stops[argc-1];
		for (int i=1;i<argc;i++)
		{	stops[i-1] = atoi(argv+i);
		}
		back = detab(argc, stops);
	}
	return back;
}