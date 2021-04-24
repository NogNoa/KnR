#include <stdio.h>
#include "KnR_getline.h"

/*
Text is nline lines, each killed by /0.
so we somehow also has to follow which lines are dead. this is beyond me.
*/


void expose(char * lini[],int  nline)
{
    char line[MAX];

    do{
        for (i=0; i <= nline; ++i){
            for (j=0)
        }

        }while (line != '\0')
}


void linearise(char * lini[])
    int len, i;
    char line[MAX];
	int mxlen = 0;

    for (i=0; (len = KnR_getline(line, MAX)) > 0; ++i)
        lini[i] = line;
    return i


void main()
{
    char * lini[MAX];
    int nline;

    nline = liearise(lini);

}
