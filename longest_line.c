#include <stdio.h>
#include "KnR_getline.h"

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


