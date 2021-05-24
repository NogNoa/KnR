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

void cmnt_inpt(char c);
void check_char(char c);
void check_close(char c);
char cmnt = 0;
char qt = 0;
char cls = 0;
_Bool delay_cmnt;

int main()
{
	char c;
	
	while((c = getchar()) != EOF)
	{
		check_char(c);
		if (!cmnt)
			check_close(c);
		if (delay_cmnt)
		{
			cmnt &= 1; //Turn off MLTCMT
			delay_cmnt = 0;
		}
	}
	printf("%d\n",cls);
	return cls;
}

void cmnt_inpt(char c)
{
	char g = getchar();
	if (c == '*' && g == '/')
		delay_cmnt = 1;
	else{
		if (c == '/' && g == '/')
			cmnt |= 1; //Turn on LNCMT
		else if (c =='/' && g == '*')
			cmnt |= 2; //Turn on MLTCMT
		ungetc(g, stdin);
	}
}

void check_char(char c)
{
	if (c == '\n')
		cmnt &= 2; //turn off LNCMT
	else if (c == '\"')
		qt ^= 2;
	else if (c == '\'')
		qt ^= 1;
	else if ((c == '/' || c == '*') && !qt)
		{
			cmnt_inpt(c);
		}
}

void check_close(char c)
{
	if (c == '(')
		cls |= 1;
	else if (c == '[')
		cls |= 2;
	else if (c == '{')
		cls |= 4;
	else if (c == '}')
		cls &= 4;
	else if (c == ']')
		cls &= 2;
	else if (c == ')')
		cls &= 1;
}