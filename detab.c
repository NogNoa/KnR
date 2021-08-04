#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MXLIN 72 /* max line length*/

void KnR_qsort(int v[], int left, int right);

int cmp(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}

int *fndcrsr(int i, int *stops, int len)
{
	int *p;
	for (p=stops;p<stops+len;++p)
		if (*p <= i && i < *(p+1))
			break;
	return p;	
}

int detab_reg(int gap)
{
	int i=0;
	char c;
	
	while ((c = getchar()) != EOF){
		if (isspace(c) && i > MXLIN)
			{	putchar('\n');
				i=0;
			}
		else if (c == '\t')
			for(int j = i % gap; j < gap; ++j, ++i)
				putchar(' ');
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

int detab1(int len, int *stops)
{
	int i=0;
	char c;
	
	while ((c = getchar()) != EOF){
		if (isspace(c) && i > MXLIN)
			{	putchar('\n');
				i=0;
			}
		else if (c == '\t')
		{	_Bool cnt=1;
			while (cnt)
			{	putchar(' ');
				 ++i;
				for (int*p=stops;p<stops+len;++p)
					if (*p==i)
						cnt=0;
				if (i > MXLIN)
					{	putchar('\n'); 
						cnt=i=0;	
					}
			}
		}
		else if (c == '\n'){ 
			putchar(c);
			i = 0;
		}
		else
		{	putchar(c);	
			++i;
		}
	}
	return i;	

}

int detab2(int len, int *stops)
{
	int i=0;
	char c;
	
	while ((c = getchar()) != EOF)
	{	if (isspace(c) && i > MXLIN)
			{	putchar('\n');
				i=0;
			}
		else if (c == '\t')
		{	int *lwbd;
			lwbd = fndcrsr(i,stops,len);
			for(int j = *lwbd; j < *(lwbd+1); ++j, ++i)
				putchar(' ');
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
	//stdin = fopen("detab.c", "r");
	
	if (argc < 2)
		/* tab-stops of 4-spaces each. */
		back = detab_reg(4);
	else 
	{	int stops[argc-1];
		for (int i=1;i<argc;i++)
		{	stops[i-1] = atoi(argv[i]);
		}
		//KnR_qsort(stops,0,argc-2);
		qsort(stops,argc-1,sizeof(int),cmp);
		back = detab2(argc-1, stops);
	}
	return back;
}
