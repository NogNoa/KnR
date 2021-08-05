#include <stdlib.h>

#include "tabbin.h"

int cmp(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}

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