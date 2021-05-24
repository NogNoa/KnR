#include <stdio.h>
/* 	comment:	cmnt
			1 line-comment 
			2 multiline comment
	quote:		qt
			1 single qoute char
			2 double qoute string
*/

void cmnt_inpt(char c, char g);
char cmnt = 0;
char qt = 0;
int main()
{
	char c,g;
	
	while((c = getchar()) != EOF)
	{
		if ((c == '/' || c == '*') && !qt)
		{
			g = getchar();
			cmnt_inpt(c,g);
		}
		else
		{
			if (c == '\n')
				cmnt &= 2; //turn off LNCMT
			else if (c == '\"')
				qt ^= 2;
			else if (c == '\'')
				qt ^= 1;
			if (!cmnt)
				putchar(c);
		}
	}
	return 0;
}

void cmnt_inpt(char c, char g)
{
	if (c == '/' && g == '/')
		cmnt |= 1; //Turn on LNCMT
	else if (c =='/' && g == '*')
		cmnt |= 2; //Turn on MLTCMT
	else if (c == '*' && g == '/')
		cmnt &= 1; //Turn off MLTCMT
	else
	{
		if (!cmnt)
			{putchar(c);putchar(g);}
	}
}
