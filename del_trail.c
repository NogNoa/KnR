#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

void main()
{	
	int c, state;
	state = IN;
	char blank[0x20];
	int i = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t'){
			state = OUT;
			blank[i] = c;
			++i;
			blank[i] = '\0';
		}	
		else{
			if (c == '\n' || c == '\r') {
				i = 0;
				blank[i] = '\0';
            }
			else if (state == OUT){
				printf("%s",blank);
				state = IN;
				i = 0;
				blank[i] = '\0'; 
			}
			putchar(c); 
		}	
	}		
}			
