#include <string.h>
#include "KnR_getline.lb.c"

// Ritchie, D.M. and Kernighan, B.W. (1988) p104

int find(int argc, char *argv[])
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
{	return find(argc, argv);
}
