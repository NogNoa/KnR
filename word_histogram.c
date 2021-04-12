#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MXWRD 10

void main()
{
	int c, hest[(MXWRD+1)], i, j;
	int len = 0;
	int state = OUT;
	
	for (i = 0; i<(MXWRD+1); ++i)
		hest[i] = 0;	
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t'){
			if (state == IN){
				if (len > MXWRD)
					len = MXWRD;
				++hest[len];
				state = OUT;
				len = 0;
			}
		}
		else {
			state = IN;
			++len;
		}
	}
	for (i=1; i<=(MXWRD - 1); ++i){
		putchar(' ');putchar('0'+i);putchar(' ');putchar(' ');
		for (j=0; j<=hest[i]; ++j)
			putchar('|');
		putchar('\n');
	}
	printf("%2d+  ",MXWRD);
	for (j=0; j<=hest[MXWRD]; ++j)
			putchar('|');
	putchar('\n');
}

//todo: add count len
// transpose
