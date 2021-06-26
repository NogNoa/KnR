#include <stdio.h>
/* 	comment:	cmnt
			1 line-comment 
			2 multiline comment
	quote:		qt
			1 single quote char
			2 double quote string
	closing:	cls
			1 parentheses
			2 brackets
			4 braces
*/

void cmnt_inpt(char c);
void check_char(char c);
void check_close(char c);
char cmnt = 0;
char qt = 0;
char last = 0;
char cls[0x100] = {0,};
char pcls = 1;
_Bool delay_cmnt;


char* main()
{
	char c;
	
	while((c = getchar()) != EOF)
	{
		check_char(c);
		if (!cmnt && !qt)
			check_close(c);
		last = c;
		if (delay_cmnt)
		{
			cmnt &= 1; //Turn off MLTCMT
			delay_cmnt = 0;
		}
	}
	pcls--;
	putchar(cls[pcls]);
	printf(" %d\n",pcls);
	return cls;
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
	else if (c == '\'' &&last != '\\' &&  !(qt&2))
		qt ^= 1;
	else if ((c == '/') && !qt)
		{
			cmnt_inpt(c);
		}
}

void check_close(char c)
{
	if (c == '(' || c == '[' || c == '{')
		cls[pcls++] = c;
	else if (((c == '}' || c == ']') && cls[pcls-1] == c-2)
			|| (c == ')' && cls[pcls-1] == c-1))
		--pcls;
}

/* well maybe a state machine design to begin with would have been better,
   but now we just have to make sure cmnt and qt state are exclusive and
   make the closing into a stack.
done: manage escape '\'
*/
