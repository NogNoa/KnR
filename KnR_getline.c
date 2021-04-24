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
{  // copy 'from' into 'to'; assume 'to' is big enough */

	for (int i = 0;(to[i] = from[i]) != '\0'; ++i)
		;
}