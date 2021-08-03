#include <stdio.h>
#include <stdlib.h>
/* max line length 72 */

int detab_reg(int gap)
{
	int i=0;
	char c;
	
	while ((c = getchar()) != EOF){
		if (c == '\t')
			for(int j = i % gap; j < gap; ++j, ++i){
				putchar(' ');
			}
		else if (c == '\n'){
			putchar(c);
			i = 0;
		}
		else
		{	if (i > 72)
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
			while (cnt && i < 72)
			{	putchar(' ');
				 ++i;
				for (int*p=stops;p<stops+len;++p)
					if (*p==i)
						cnt=0;
			}
			if (i > 72)
			{	putchar('\n');
				i=0;
			}
		}
		else if (c == '\n'){
			putchar(c);
			i = 0;
		}
		else if (c == ' ' && i > 72)
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