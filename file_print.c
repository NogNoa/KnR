#include <stdio.h>
#include <stdlib.h>
#define PAGELINI 120

//external
char ** strarr_allocate(int nom_cnt, char **nomi, char **codii);
FILE * file_switch(FILE *codex, char** codii);

//internal
int file_print(FILE *codex);

int main(int argc, char *argv[])
{
	char **codii;
	FILE *codex;

	if (argc > 1)
		codii = strarr_allocate(--argc, ++argv, codii);
	
	while ((codex = file_switch(codex, codii)) != NULL)
		file_print(codex);
	return EXIT_SUCCESS;
}

int file_print(FILE *codex)
{
	static int page_num = 1;
	       int line_num    ;
	size_t maxline = 0200;
	char *line = (char *) malloc(maxline);
	_Bool nextpage=1;

	while (nextpage)
	{	for(line_num=1;line_num<PAGELINI;line_num++)
		{	if (!nextpage)
				line="\n";
			else
		 		nextpage =getline(&line, &maxline, codex);
			printf("%s",line);
		}
		printf("%40d",page_num++);
	}
	return page_num;
}
