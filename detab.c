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
			else for (int j=i;i++ <= (j/gap*gap + 1);)
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

int detab(int len, int *stops)
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
			while(i++ < *(lwbd+1)) 
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
	//stdin = fopen("detab.c", "r");
	
	if (argc < 2)
		/* tab-stops of 4-spaces each. */
		back = detab_reg(0,4);
	else 
	{	int n=0,m=0;
		for (int i=1;i<argc;i++)
		{	if (*argv[i] == '+')
				n=atoi(argv[i]+1);
			else if (*argv[i] == '-')
				m=atoi(argv[i]+1);
		}
		if (n)	
			back = detab_reg(m,n);
		else 
		{	int stops[argc+1];
			for (int i=1;i<argc;i++)
			{	stops[i] = atoi(argv[i]);
			}
			stops[0]=0; stops[argc+1]=MXLIN;
			//KnR_qsort(stops,0,argc-2);
			qsort(stops,argc+1,sizeof(int),cmp);
			if (0< stops[0] || stops[argc] > MXLIN)
				fprintf(stderr,"ERROR: Please enter tabstops between 0 and %d\n",MXLIN);
			back = detab(argc+1, stops);
		}
	}
	return back;
}

/* todo: make combined mathod that just create 1 list of stops from both speicel and regular arguments */
