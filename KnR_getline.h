#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MAXLINE
#define MAXLINE 0x400
#endif
typedef struct{
	int nline;  //number of lines
	int mxlen;  //length of longest line
	int *linlen; //array for the length of each line
	char **lini; //array of pointers to each line
} page;

int KnR_getline (char line[], int maxline);
void copy(char to[], char from[]);
_Bool pascal_getline(char line[], int maxline);
int ptr_KnR_getline(char *s, int n);
page linearise(void);

