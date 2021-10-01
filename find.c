// Ritchie, D.M. and Kernighan, B.W. (1988) p63 p104
//original

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
	{	unsigned int except, number:1;
	}state;

//external
char ** strarr_allocate(int argc, char **argv, char **codii);
//internal
int find(char *, state, char **);

int main(int argc, char *argv[])
{	char c, *pattern; 
	int found;
	state stt = {0,0};

	char **codii;

	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
		switch (c) 
		{case 'x':
			stt.except = 1;
			break;
		case 'n':
			stt.number = 1;
			break;
		case 'f':
			fprintf(stderr, "before listing files, give me the pattern\n");
			argc = 0;
			found = -1;
			break;
		default:
			fprintf(stderr,"find: illegal option %c\n", c);
			argc = 0;
			found = -1;
			break;
		}
	if (--argc <= 0)
	{	printf("Usage: find -x -n pattern -f files\n");
		return found;
	}
	
	pattern = *argv;

	if (--argc > 1 && strncmp(*++argv,"-f",2) == 0)
		codii = strarr_allocate(argc, ++argv, codii);
	else
	{	codii=malloc(1);
		*codii = "";
	}
	
	found += find(pattern, stt, codii);
	
	return found;
}

//external
FILE * file_switch(FILE *codex, char** codii);

int find(char *str, state stt, char **codii)
{ /* find: print lines that match pattern from 1st arg */
	long lineno = 0;
	FILE *codex;
	int count_codii = 0, found;
	size_t maxline = 0200;
	char *line = (char *) malloc(maxline);

	for (;(codex = file_switch(codex, codii)) != NULL; count_codii++)
	{	printf("%i  -  %s:\n", count_codii, codii[count_codii]);
		while (getline(&line, &maxline, codex) > 0)
		{	lineno++;
			if ((strstr(line, str) != NULL) != stt.except) 
			{	putchar('\t');
				if (stt.number)
					printf("%ld", lineno);
				printf(":%s", line);
				found++;
			}
		}
		putchar('\n');
	}
	free(line);
	return found;
}

/* Make codii array. make allocation function. make switch file function. */
