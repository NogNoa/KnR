#include <stdio.h>
#ifndef MAXLINE
#define MAXLINE 0x400
#endif

int KnR_getline (char line[], int maxline);
void copy(char to[], char from[]);
_Bool pascal_getline(char line[], int maxline);
int ptr_KnR_getline(char *s, int n);

#include "KnR_getline.lb.c"
