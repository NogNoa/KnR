#include <stdio.h>
/* 	comment:	cmnt
			1 line-comment 
			2 multiline comment
	quoute:		qt
			1 single qoute char
			2 double qoute string
	closing:	cls
			1 parenteses
			2 brackets
			4 braces
*/

void cmnt_inpt(char c, char g);
char cmnt = 0;
char qt = 0;
char cls = 0;

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
		else if (c == '\n')
				cmnt &= 2; //turn off LNCMT
		else if (c == '\"')
				qt ^= 2;
		else if (c == '\'')
				qt ^= 1;
		cls_ceck(c)
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
		if ((g == '(' || g == '[' or g == '{'))
			cls_check(g)
	}
}