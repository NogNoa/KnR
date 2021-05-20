#include <stdio.h>
# define BTHCMNT 3 // both comment modes are on
#define MLTCMNT 2 /* multiline comment */
#define LNCMNT 1 // one line comment 
#define PRG 0 /* part of the code to be compiled */

void stt_prg(char);
void stt_lncmnt(char);
void stt_mltcmnt(char);

void main()
{

	char g;
	state = PRG

	while(char c = getchar() != EOF)
		switch(state) {
			case PRG: stt_prg(c); break;
			case LNCMNT: stt_lncmnt(c);
			case MLTCMNT: stt_mltcmnt(c); break;
		}

}

void stt_prg(char c)
{
	if (c == '/')
	{
			g = getchar();
			if (g == '*')
				state |= 2;
			else if (g == '/')
				state |= 1;
			else
				printf("/d/d",c,g);
	}
	else
		putchar(c);
}

void stt_lncmnt(char c)
{
	if (c == '\n')
		stat &= 2;
}

void stt_mltcmnt(char c)
{
	if (c == '*')
	{
		g = getchar()
		if (g == '/')
			state &= 1;
		
	}

}