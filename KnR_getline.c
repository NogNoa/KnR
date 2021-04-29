#include <stdio.h>

int KnR_getline(char s[], int lim)
{  // read a line into s, return lenght

	int c, i;

	for (i=0; i < lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c== '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{  // copy 'from' into 'to'; assume 'to' is big enough

	for (int i = 0;(to[i] = from[i]) != '\0'; ++i)
		;
}

_Bool pascal_getline(char s[], int lim)
{ // give a line with length in the begining
		// high byte is ones-complement, hence breaks at lengths > 0xFEFF = 65279

	char c;
	int len;

	for (len=2; len < lim-1 && (c=getchar()) !=EOF && c!='\n'; ++len)
		s[len] = c;
	if (c== EOF)
		return 0;
	if (c== '\n') {
		s[len++] = c;
	}
	s[len] = '\0';

	len = (short) len - 2;
	s[1] = len & 0xFF;
	s[0] = (len >> 8) ^ 0xFF ;

	return 1;
}
