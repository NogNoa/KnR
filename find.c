// Ritchie, D.M. and Kernighan, B.W. (1988) p63 p104
//original

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
	{	int found;
		_Bool except, number;
	}state;

int find(char *, state, char **);

char ** strarr_allocate(int argc, char **argv, char **codii)
{	char buffer[0201];
	size_t len;
	
	codii = calloc(argc, sizeof (char *));
	char **back = codii;
	
	while (argc--> 0)
	{	strncpy(buffer, *++argv, 0200);
		*codii = malloc(strlen(buffer)+1);
		strcpy(*codii++,buffer);
	}
	return back;
}

int main(int argc, char *argv[])
{	char c, *pattern; 
	state stt = {0,0,0};
	FILE *codex;

	char **codii={""};

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
	if (--argc <= 0)
		printf("Usage: find -x -n pattern -f files\n"); 
	else
		pattern = *argv;

	if (--argc > 1 && strncmp(*++argv,"-f",2) == 0)
		codii = strarr_allocate(argc, argv, codii);

	stt.found = find(pattern, stt, codii);
	return stt.found;
}

FILE * file_switch(FILE *codex, char** codii);

int find(char *str, state stt, char **codii)
{ /* find: print lines that match pattern from 1st arg */
	long lineno = 0;
	char *line;
	FILE *codex;
	size_t maxline = 0200;
	line = (char *) malloc(maxline);

	while ((codex = file_switch(codex, codii)) != NULL)
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

FILE * file_switch(FILE *codex, char** codii)
{
	static int count_codii; //static variables are guaranteed to init 0;

	if (count_codii==0)
	{	if (!*codii)
		{	count_codii++;
			return stdin;
		}
	}
	else
		fclose(codex);
	return fopen(codii[count_codii++],"r");
}

/* Make codii array. make allocation function. make switch file function. */
