#include <stdio.h>
#include <stdlib.h>
#define PAGELINI 120

//external
char ** strarr_allocate(int nom_cnt, char **nomi, char **codii);
FILE * file_switch(FILE *codex, char** codii);

int main(int argc, char *argv[])
{
	char **codii;
	FILE *codex;
	int count_codii = 0;

	if (argc > 1)
		codii = strarr_allocate(--argc, ++argv, codii);
	
	while ((codex = file_switch(codex, codii)) != NULL)
		file_print(codex);
	return EXIT_SUCCESS;
}

int file_print(File *codex)
{
	static int page_num = 1;
	       int line_num = 1;
	size_t maxline = 0200;
	char *line = (char *) malloc(maxline);

	for (getline(&line, &maxline, codex) > 0)
	{	while(line_num<PAGELINI)
			printf("%s",line);
		printf("%40d",page_num++)

}
