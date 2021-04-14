#include <stdio.h>
#define MAXLINE 1000

int KnR_getline(char s[], int lim)
{  // read a line into s, return lenght

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

int main()
{  /* print the longest input line */

	int len;
	char line[MAXLINE];
	
	while ((len = KnR_getline(line, MAXLINE)) > 0)
	if (len > 80) {
		printf("%s", line);
	}
	return 0;
}
