#include <string.h>
#include <stdio.h>

#define MAXLINE 02000

// Ritchie, D.M. and Kernighan, B.W. (1988) p104

int find(int argc, char *argv[], struct stt state);

int main(int argc, char *argv[])
{	char c; 
	struct stt
	{	int found;
		_Bool except, number;
	} state = {0,0,0};

	
	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
		switch (c) 
		{	case 'x':
				state.except = 1;
			break;
			case 'n':
				state.number = 1;
			break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				state.found = -1;
			break;
		}
	return find(argc, argv, state);
}

int find(int argc, char *argv[], struct stt state)
{ /* find: print lines that match pattern from 1st arg */
	char line[MAXLINE];
	long lineno = 0;

	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else while (fgets(line, MAXLINE, stdin) > 0)
	{	lineno++;
		if ((strstr(line, *argv) != NULL) != state.except) 
		{	if (state.number)
				printf("%ld:", lineno);
			printf("%s", line);
			state.found++;
		}
	}
	return found;
}