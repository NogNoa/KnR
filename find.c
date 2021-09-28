// Ritchie, D.M. and Kernighan, B.W. (1988) p63 p104

#include <string.h>
#include <stdio.h>

#define MAXLINE 02000
typedef struct
	{	int found;
		_Bool except, number;
	}state;

int find(int argc, char *argv[], state stt);

int main(int argc, char *argv[])
{	char c; 
	state stt = {0,0,0};

	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
		switch (c) 
		{	case 'x':
				stt.except = 1;
			break;
			case 'n':
				stt.number = 1;
			break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				stt.found = -1;
			break;
		}
	return find(argc, argv, stt);
}

int find(int argc, char *argv[], state stt)
{ /* find: print lines that match pattern from 1st arg */
	char line[MAXLINE];
	long lineno = 0;

	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else while (fgets(line, MAXLINE, stdin) > 0)
	{	lineno++;
		if ((strstr(line, *argv) != NULL) != stt.except) 
		{	if (stt.number)
				printf("%ld:", lineno);
			printf("%s", line);
			stt.found++;
		}
	}
	return stt.found;
}