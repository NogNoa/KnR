#include <stdio.h>
/* tab-stops of 4-spaces each. */

int main(void)
{
	int i=0;
	char c;
	
	while ((c = getchar()) != EOF){
		if (c == '\t')
			for(int j = i % 4; j < 4; ++j, ++i){
				putchar(' ');
			}
		else if (c == '\n'){
			putchar(c);
			i = 0;
		}
		else{
			putchar(c);
			++i;
		}
	}
	return i;
}