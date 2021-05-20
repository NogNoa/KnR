#include <stdio.h>
#define BTHCMNT 3 // both comment modes are on
#define MLTCMNT 2 /* multiline comment */
#define LNCMNT 1 // one line comment 
#define PRG 0 /* part of the code to be compiled */

void cmnt_inpt(char c, char g);
short state = PRG;
int main()
{
	char c,g;
	
	while((c = getchar()) != EOF)
	{
		if (c == '/' || c == '*')
		{
			g = getchar();
			cmnt_inpt(c,g);
		}
		else
		{
			if (c == '\n')
				state &= 2; //turn off LNCMT
			if (!state)
				putchar(c);
		}
	}
	return 0;
}

void cmnt_inpt(char c, char g)
{
	if (c == '/' && g == '/')
		state |= 1; //Turn on LNCMT
	else if (c =='/' && g == '*')
		state |= 2; //Turn on MLTCMT
	else if (c == '*' && g == '/')
		state &= 1; //Turn off MLTCMT
	else
	{
		if (!state)
			{putchar(c);putchar(g);}
	}
}
