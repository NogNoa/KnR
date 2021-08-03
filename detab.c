#include <stdio.h>

int main(int argc, char *argv)
{
	if (argc < 2)
		/* tab-stops of 4-spaces each. */
		back = detab_reg(4)
	else 
		back = detab(argv)
	return back
}

int detab_reg(int gap)
{
	int i=0;
	char c;
	
	while ((c = getchar()) != EOF){
		if (c == '\t')
			for(int j = i % gap; j < gap; ++j, ++i){
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

int detab(char *argv)
{
	return 0;
}
