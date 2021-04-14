#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

void main()
{
	int c, state;
	state = OUT;
	char blank[0x20];
	int i = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t'){
			state = OUT;
			blank[i] = c;
			++i;
		}
		else{
			if (c == '\n'){
				i = 0;
				blank[0] = '\0';
            }
			else if (state == OUT){
				printf("%s",blank);
				state = IN;
				i = 0;
				blank[0] = '\0';
			}
			putchar(c);
		}
	}
}
