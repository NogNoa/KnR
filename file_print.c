#include <stdio.h>
#include <stdlib.h>
#define PAGELINI 120

//external
char ** strarr_allocate(int nom_cnt, char **nomi, char **codii);
FILE * file_switch(FILE *codex, char** codii, int index_codii);

int main(int argc, char *argv[])
{
	char **codii;
	FILE *codex;
	int count_codii = 0;

	if (argc > 1)
		codii = strarr_allocate(--argc, ++argv, codii);
	
	while ((codex = file_switch(codex, codii, count_codii)) != NULL)
		puts(codii[count_codii++]);
	return EXIT_SUCCESS;
}