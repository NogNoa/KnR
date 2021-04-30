#include "KnR_getline.h"
#define MAX 0xFF

/*
Text is nline lines, each killed by /0.
so we somehow also has to follow which lines are dead. this is beyond me.
*/


void expose(char * lini[],int  nline)
{
	char line[MAX];

	do{
		for (int i=0; i <= nline; ++i){
			for (int j=0; 0;)
				;
		}

		}while (0);
}


int linearise(char * lini[])
{
	int len, i;
	char line[MAX];
	int mxlen = 0;

	for (i=0; pascal_getline(line, MAX); ++i){
		line[0] = len;
		lini[i] = line;
	}
	return i;
}


void main()
{
	char * lini[MAX];
	int nline;

	nline = linearise(lini);
	printf("%d\n", (char) * lini[3]);

}
