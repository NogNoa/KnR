#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MAXLINE
#define MAXLINE 0x400
#endif
int mxlen;
char * lini[MAXLINE];

int KnR_getline (char line[], int maxline);
void copy(char to[], char from[]);
_Bool pascal_getline(char line[], int maxline);
int ptr_KnR_getline(char *s, int n);
int linearise(void);

