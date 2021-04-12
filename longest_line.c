#include <stdio.h>
#define MAXLINE 1000

int KnR_getline (char line[], int maxline);
void copy(char to[], char from[]);

int main()
{  /* print the longest input line */

	int len;
	int max = 0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while ((len = KnR_getline(line, MAXLINE)) > 0)
	if (len > max) {
		max = len;
		copy(longest, line);
	}

	if (max > 0)
		printf("%s", longest);
	return 0;
}

int KnR_getline(char s[], int lim)
{  /* read a line into s, return lenght */

	int c, i;

	for (i=0; i < lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c== '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{  /* copy 'from' into 'to'; assume 'to' is big enough */

	for (int i = 0;(to[i] = from[i]) != '\0'; ++i)
		;
}
