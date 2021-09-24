#include <string.h>
#include "KnR_getline.lb.c"
#include "add_remove-string.lb.c"

// Ritchie, D.M. and Kernighan, B.W. (1988) p63

char pattern[] = "ould"; /* pattern to search for */

int find40()
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

// Ritchie, D.M. and Kernighan, B.W. (1988) p104

int find54(int argc, char *argv[])
{ /* find: print lines that match pattern from 1st arg */
	char line[MAXLINE];
	int found = 0;
	
	if (argc != 2)
		printf("Usage:find pattern\n");
	else while (KnR_getline(line, MAXLINE) > 0)
		if (strstr(line, argv[1]) != NULL)
		{	printf("%s", line);
			found++;
		}
	return found;
}


int find55(int argc, char *argv[])
{ /* find: print lines that match pattern from 1st arg */
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;
	
	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
		switch (c) 
		{	case 'x':
				except = 1;
			break;
			case 'n':
				number = 1;
			break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				found = -1;
			break;
		}
	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else while (KnR_getline(line, MAXLINE) > 0)
	{	lineno++;
		if ((strstr(line, *argv) != NULL) != except) 
		{	if (number)
				printf("%ld:", lineno);
			printf("%s", line);
			found++;
		}
	}
	return found;
}


int main(int argc, char *argv[])
{	return find55(argc, argv);
}
