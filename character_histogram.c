#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

void main()
{
	char mxchar = (char)-1;
	int i, j, max = mxchar, min =0;
	char hest[mxchar], c;
	
	for (i = 0; i<mxchar; ++i)
		hest[i] = 0;
	
	while ((c = getchar()) != EOF) {
			++hest[c];
	}

	for (i=0; hest[i]==0;++i)
		min=i;
	for (i=mxchar;hest[i]==0;--i)
		max=i;
	
	printf("%x %x",min, max);

	for (i=min+1; i<max; ++i){
		putchar(i);printf("  ");
		for (j=0; j<=hest[i]; ++j)
			putchar('|');
		putchar('\n');
	}
}
