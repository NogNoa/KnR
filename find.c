#include <string.h>
#include "KnR_getline.lb.c"
#include "add_remove-string.lb.c"

// Ritchie, D. and Kernighan, W. (1988) p104

int find5(int argc, char *argv[])
{ /* find: print lines that match pattern from 1st arg */
	char line[MAXLINE];
	int found = 0;
	
	if (argc != 2)
		printf("Usage: pattern\n");
	else while (KnR_getline(line, MAXLINE) > 0)
		if (strstr(line, argv[1]) != NULL)
		{	printf("%s", line);
			found++;
		}
	return found;
}

// Ritchie, D. and Kernighan, W. (1988) p63

char pattern[] = "ould"; /* pattern to search for */

int find4()
{	/* find all lines matching pattern */
	char line[MAXLINE];
	int found = 0;
	
	while (KnR_getline(line, MAXLINE) > 0)
		if (strindex_1st(line, pattern) >= 0) 
		{	printf("%s", line);
			found++;
		}
	return found;
}

int main(int argc, char *argv[])
{	return find5(argc, argv);
}
