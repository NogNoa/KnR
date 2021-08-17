
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 0200
enum { NAME, PARENS, BRACKETS };

int gettoken(void);

char token[MAXTOKEN]; /* last token string */
char out[02000];