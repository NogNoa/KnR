#include <stdio.h>
int main()
{
	int c;

	for (c = 0; c != EOF; c = getchar())
	{
		if ((c == '\t') || (c == ' '))
		{
			do 
				c = getchar();
			while ((c  == '\t') || (c == ' ' ));
			putchar(' ');
		}
		putchar(c);
	}
	return 0;
}
