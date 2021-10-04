#include <stdlib.h>

#include "tabbin.h"

static int cmp(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}

struct tabbin arg_prcs(int argc, char *argv[])
{
	int *stops = malloc(argc+1);
	int n=0,m=0;
	stops[0]=0; stops[argc+1]=MXLIN;
	for (int i=1;i<argc;i++)
	{	if (*argv[i] == '+')
			n=atoi(argv[i]+1);
		else if (*argv[i] == '-')
			m=atoi(argv[i]+1);
		else
			stops[i] = atoi(argv[i]);
	}
	qsort(stops,argc+1,sizeof(int),cmp);
	if (0< stops[0] || stops[argc] > MXLIN)
		fprintf(stderr,"ERROR: Please enter tabstops between 0 and %d\n",MXLIN);
	struct tabbin taby={.n=n, .m=m, .stops=stops};
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
	int gpstp= (gap > 0) ? start + ((i-start)/gap+1)*gap : start; //gap stop, we don't want an arithmathic error
	gpstp = (gpstp > start) ? gpstp : start;
	int *hibd; //high boundary
	hibd = fndcrsr(i,stops,len);
	return  (gpstp < *(hibd)) ? gpstp : *(hibd);
}

