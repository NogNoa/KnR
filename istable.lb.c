/*
8 types
  1 -  cntl: 00-1f |7f
  2 - space: 09 | blank | 20
  4 - punct: 21-2f | 3a-40 | 4b-60 | 7b-7e
  8 - digit: 30-39
 16 - UPPER: 41-46
 32 - lower: 61-7A
 64 -xdigit: digit | 41-46 | 61-66
128 - blank: 0A-0D

compound types:
alpha: UPPER | lower
alnum: alpha | digit
graph: punct | alnum 
print: graph | 20 

atomic types
cntl only: 00-08 | Oe-1f | 7f
blank
tab 09
space 20
punct
digit
upper
lower

*/

#define CNTL  0x1
#define  SPC  0x2
#define PNCT  0x4
#define  DGT  0x8
#define   UP 0x10
#define  LOW 0x20
#define XDGT 0x40
#define BLNK 0x80

/* edited from code and designs by codybartfast john@codybartfast.com and Gregory Pietsch gpietsch@comcast.net 
at https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_7:Exercise_9
*/

#include <ctype.h>
#include <limits.h>

static unsigned char map[UCHAR_MAX]={0};

void tis_init(void)
{
	int i;

	for (i = 0; i < UCHAR_MAX; i++)
	{	if (ispunct(i))
			{map[i] |= PNCT;}
		else if (isdigit(i))
			{map[i] |= DGT;}
		else if (isupper(i))
			{map[i] |= UP;}
		else if (islower(i))
			{map[i] |= LOW;}
		else
		{	if(iscntrl(i))
				{map[i] |= CNTL;}
			if (isspace(i))
			{	map[i] |= SPC;
				if (isblank(i))
					{map[i] |= BLNK;}
			}
		}
		if (isxdigit(i))
			{map[i] |= XDGT;}
	}
} 

_Bool tispunct(char c)
{
	int i = (int) c;

	return (_Bool) (map[i] & PNCT);
}

_Bool tisspace(char c)
{
	int i = (int) c;

	return (_Bool) (map[i] & SPC);
}

_Bool tisdigit(char c)
{
	int i = (int) c;

	return (_Bool) (map[i] & DGT);
}

_Bool tiscntl(char c)
{
	int i = (int) c;

	return (_Bool) (map[i] & CNTL);
}

_Bool tisupper(char c)
{
	int i = (int) c;

	return (_Bool) (map[i] & UP);
}

_Bool tislower(char c)
{
	int i = (int) c;

	return (_Bool) (map[i] & LOW);
}

_Bool tisxdigit(char c)
{
	int i = (int) c;

	return (_Bool) (map[i] & XDGT);
}

_Bool tisblank(char c)
{
	int i = (int) c;

	return (_Bool) (map[i] & BLNK);
}

_Bool tisalpha(char c)
{
	int i = (int) c;

	return (_Bool) (map[i] & (UP | LOW));
}

_Bool tisalnum(char c)
{
	int i = (int) c;

	return (_Bool) (map[i] & (UP | LOW | DGT));
}

_Bool tisgraph(char c)
{
	int i = (int) c;

	return (_Bool) (map[i] & (UP | LOW | DGT | PNCT));
}

_Bool tisprint(char c)
{
	int i = (int) c;

	return (_Bool) (map[i] & (UP | LOW | DGT | PNCT)) | (i == ' ');
}