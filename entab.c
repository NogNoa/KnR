#include <stdio.h>
/* tab-stops of 4-spaces each. */

int main(void)
{
	int i=0;
	char c;
	int s=0;
	int r;
	
	while ((c = getchar()) != EOF){
		if (c == ' ')
			++s;
			if (s >= (r = (4 - i % 4))){
				putchar('\t');
				s -= r;
				i = 0;
			}
		else if (c == '\t'){
			putchar('\t');
			i = 0;
		}
		else{
			for (;s>0;--s)
				putchar(' ');
			putchar(c);
			++i;
		}
		if (c == '\n')
			i = 0;
	}
	return i;
}