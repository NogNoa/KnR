// Ritchie, D.M. and Kernighan, B.W. (1988) p63 p104
//original

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
	{	int found;
		_Bool except, number;
	}state;

int find(char *, state, FILE *);

char ** strarr_allocate(int argc, char **argv)
{	char *codii[argc];
	char buffer[0200];
	size_t len;
	char **back = codii;
	
	for (; argc> 0;argc--)
	{	len=strncpy(buffer, *argv, 0200);
		*codii++ = malloc(len+1);
	}
	return back;
}

int main(int argc, char *argv[])
{	char c, *pattern; 
	state stt = {0,0,0};
	FILE *codex;

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
			fprintf(stderr, "before listing files, give me the pattern");
			argc = 0;
			stt.found = -1;
			break;
		default:
			fprintf(stderr,"find: illegal option %c\n", c);
			argc = 0;
			stt.found = -1;
			break;
		}
	if (!**argv)
		printf("Usage: find -x -n pattern -f files\n"); 
	else
		pattern = *argv;

	if (--argc > 1 && strncmp(*++argv,"-f",2) == 0)
		codii = strarr_allocate(argc, argv);
	else
		codii = {"stdin"}; 

	stt.found = find(pattern, stt, stdin);
	return stt.found;
}

int find(char *str, state stt, FILE *codex)
{ /* find: print lines that match pattern from 1st arg */
	long lineno = 0;
	char *line;
	size_t maxline = 0200;
	line = (char *) malloc(maxline);

	while (getline(&line, &maxline, codex) > 0)
	{	lineno++;
		if ((strstr(line, str) != NULL) != stt.except) 
		{	if (stt.number)
				printf("%ld:", lineno);
			printf("%s", line);
			stt.found++;
		}
	}
	return stt.found;
}

/* Make codii array. make allocation function. make switch file function. */
