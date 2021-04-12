#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

void main()
{
	int c, hest[11], i, j;
	int len = 0;
	int state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t'){
			if (state == IN){
				if (len > 10)
					len = 10;
				++hest[len];
				state = OUT;
			}
		}
		else {
			state = IN;
			++len;
		}
	}
	for (i=1; i<=9; ++i){
		printf('%d \t %d', i, hest[i]);
	}
	printf('%d+ \t %d',10, hest[10]);
}

//todo: add count len
// transpose