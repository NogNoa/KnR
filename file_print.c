#include <stdio.h>
#include <stdlib.h>
#define PAGELINI 74 /*≈79*sqrt(2)*2/3 
79 is the python line, sqrt(2) for A-series page, 
2/3 approximetly hight to width of a latin grapheme
*/


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
	_Bool lastpage=0;

	while (!lastpage)
	{	for(line_num=0;line_num<PAGELINI;line_num++)
		{	if (lastpage)
				line="\n";
			else
		 		lastpage =(getline(&line, &maxline, codex) == EOF);
			printf("%s",line);
		}
		printf("%40d\n",page_num++);
	}
	return page_num;
}
