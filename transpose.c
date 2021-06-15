#include "KnR_getline.h"
#define MAX 0x100

/*
Text is nline lines, each killed by /0.
so we somehow also has to follow which lines are dead. this is beyond me.
15.6.21 still not prepered
*/


void expose(char * lini[],int  nline)
{
	char line[MAX];

	do{
		for (int i=0; i <= nline; ++i)
		{	for (int j=0; 0;)
				;
		}

	}while (0);
}

int mxlen = 0;
char * lini[MAX];

int linearise(void)
{
	char line[MAX];
	int i,len = 0;

	for (i=0; (len = KnR_getline(line, MAX)); ++i)
	{	lini[i] = line;
		if (len>mxlen)
			mxlen=len;
	}
	return i;
}


void main()
{
	int many_line;

	many_line = linearise();
	for (int i;i<50;++i)
		printf("%s", lini[i]);
}
