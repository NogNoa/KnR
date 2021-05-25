#include <stdio.h>
/* 	comment:	cmnt
			1 line-comment 
			2 multiline comment
	quote:		qt
			1 single qoute char
			2 double qoute string
*/

void cmnt_inpt(char c);
void check_char(char c);
char cmnt = 0;
char qt = 0;
char last = 0;
_Bool delay_cmnt;
int main()
{
	char c;
	
	while((c = getchar()) != EOF)
	{
		check_char(c);
		if (!cmnt)
			putchar(c);
		last = c;
		if (delay_cmnt)
		{
			cmnt &= 1; //Turn off MLTCMT
			delay_cmnt = 0;
		}
	}
	return 0;
}

void cmnt_inpt(char c)
{
	char g;
	if (last == '*')
		delay_cmnt = 1;
	else{
		g = getchar();
		if (c == '/' && g == '/' && !(cmnt&2))
			cmnt |= 1; //Turn on LNCMT
		else if (c =='/' && g == '*' && !(cmnt&1))
			cmnt |= 2; //Turn on MLTCMT
		ungetc(g, stdin);
	}
}

void check_char(char c)
{
	if (c == '\n')
		cmnt &= 2; //turn off LNCMT
	else if (c == '\"' && last != '\\' && !(qt&1))
		qt ^= 2;
	else if (c == '\'' && last != '\\' && !(qt&2))
		qt ^= 1;
	else if ((c == '/') && !qt)
		{
			cmnt_inpt(c);
		}
}
