#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

void main()
{
	char mxchar = (unsigned char) -1 >> 1;
	char mnchar = ' ';
	int i, j;
	char hest[mxchar], c;
	
	for (i = 0; i<mxchar; ++i)
		hest[i] = 0;
	
	while ((c = getchar()) != EOF) {
			++hest[c];
	}

	for (i=mnchar; i<mxchar; ++i){
		putchar(i);printf("  ");
		for (j=0; j<=hest[i]; ++j)
			putchar('|');
		putchar('\n');
	}
}
