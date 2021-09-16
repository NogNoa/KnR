#include <ctype.h>
#include "tree_count.h"

#define MAXWORD 0200

struct tnode *craddtree(struct tnode *, char *);
void crtreeprint(struct tnode *);
char getword(char *, int); //from molon.lb.c
_Bool shouldignore(char* word, char* ignore_me[], int);


static char* banal[] = {
	"and",
	"the",
	"of",
	"a",
	"an",
	"to",
	"in",
	"that",
	"this",
	"have",
	"has",
	"had",
	"not",
	"for",
	"on",
	"with",
	"as",
	"do",
	"at",
	"but",
	"by",
	"from",
};

int main()
{ /* word frequency count */
	struct tnode *root;
	char word[MAXWORD];
	int size_banal = sizeof banal / sizeof *banal;

	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]) && !shouldignore(word,banal,size_banal))
			root = craddtree(root, word);
	crtreeprint(root);
	return 0;
}
