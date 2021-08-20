
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 0200
enum { NAME, PARENS, BRACKETS };

int gettoken(void);
void ungettoken(int len); //0 for please calculate for me */ 

char token[MAXTOKEN]; /* last token string */
char out[02000];

