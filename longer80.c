#include <stdio.h>
#include "KnR_getline.h"

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
