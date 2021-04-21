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
			if (s >= ( r = i % 4)){
				putchar('\t');
				s -= r;
				i += r;
			}
			else{
				++s;
			}
		else if (c == '\t'){
			putchar('\t');
			i += (i % 4);
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