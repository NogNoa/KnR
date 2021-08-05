#include <stdio.h>
#define MXLIN 72 /* max line length*/

struct tabbin arg_prcs(int argc, char *argv[]);

int *fndcrsr(int i, int *stops, int len) //find cursor
{
	int *p;
	for (p=stops;p<stops+len;++p)
		if (*p <= i && i < *(p+1))
			break;
	return p+1;	
}


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
		{	int *hibd; //high boundary
			hibd = fndcrsr(i,stops,len);
			int gpstp = start + ((i-start)/gap+1)*gap; //gap stop
			if (i<start) while (i++ < start)
				putchar(' ');
			else while(i++ < *(hibd) && i < gpstp) 
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

struct tabbin 
{	int n,m;
	int *stops;
};

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
