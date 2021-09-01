#include <stdio.h>

#define MXLIN 72 /* max line length*/

struct tabbin 
{	int n,m;
	int *stops;
};

struct tabbin arg_prcs(int argc, char *argv[]);
int fndstp (int start, int gap, int *stops, int len, int i);
