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

int *fndcrsr(int i, int *stops, int len) //find cursor
{
	int *p;
	for (p=stops;p+1<stops+len;++p)
		if (*p <= i && i < *(p+1))
			break;
	return p+1;	
}

int fndstp (int start, int gap, int *stops, int len, int i)
{ 
	int gpstp = start + ((i-start)/gap+1)*gap; //gap stop
	gpstp = (gpstp > start) ? gpstp : start;
	int *hibd; //high boundary
	hibd = fndcrsr(i,stops,len);
	return  (gpstp < *(hibd)) ? gpstp : *(hibd);
}