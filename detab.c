#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MXLIN 72 /* max line length*/

void KnR_qsort(int v[], int left, int right);

int cmp(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}

int *fndcrsr(int i, int *stops, int len) //find cursor
{
	int *p;
	for (p=stops;p<stops+len;++p)
		if (*p <= i && i < *(p+1))
			break;
	return p;	
}

int detab_reg(int start,int gap)
{
	int i=0;
	char c;
	
	while ((c = getchar()) != EOF)
	{	if (isspace(c) && i > MXLIN)
			{	putchar('\n');
				i=0;
			}
		else if (c == '\t')
			if (i<start) while (i++ < start)
				putchar(' ');
			else for (int j=i;i++ < (j/gap+1)*gap;)
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

int detab(int start, int gap, int *stops, int len)
{
	int i=0;
	char c;
	
	while ((c = getchar()) != EOF)
	{	if (isspace(c) && i > MXLIN)
			{	putchar('\n');
				i=0;
			}
		else if (c == '\t')
		{	int *lwbd; //low boundary
			lwbd = fndcrsr(i,stops,len);
			int gpstp = (i/gap+1)*gap;
			if (i<start) while (i++ < start)
				putchar(' ');
			else while(i++ < *(lwbd+1) && i < gpstp) 
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

struct tabbin arg_prcs(int argc, char *argv[])
{
	struct tabbin taby;
	taby.stops = malloc(argc+1);
	taby.n=0,taby.m=0;
	taby.stops[0]=0; taby.stops[argc+1]=MXLIN;
	for (int i=1;i<argc;i++)
	{	if (*argv[i] == '+')
			taby.n=atoi(argv[i]+1);
		else if (*argv[i] == '-')
			taby.m=atoi(argv[i]+1);
		else
			taby.stops[i] = atoi(argv[i]);
	}
	qsort(taby.stops,argc+1,sizeof(int),cmp);
	if (0< taby.stops[0] || taby.stops[argc] > MXLIN)
		fprintf(stderr,"ERROR: Please enter tabstops between 0 and %d\n",MXLIN);
	return taby;

}

int main(int argc, char *argv[])
{
	int back;
	struct tabbin taby;
	//stdin = fopen("detab.c", "r");
	
	if (argc < 2)
		/* tab-stops of 4-spaces each. */
		back = detab_reg(0,4);
	else 
	{	taby = arg_prcs(argc, argv);
		back = detab_reg(taby.m,taby.n);
	}
	return back;
}

/* todo: make combined mathod that just create 1 list of stops from both speicel and regular arguments */
