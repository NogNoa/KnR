#include <ctype.h>
#include "tree_count.h"

#define MAXWORD 0200

struct tnode *craddtree(struct tnode *, char *, int);
void crtreeprint(struct tnode *);
char lngetword(char *, int); //from molon.lb.c
_Bool shouldignore(char* word, const char* ignore_me[], int);


static const char* banal[] = {
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
	const int size_banal = sizeof banal / sizeof *banal;
	int iline = 1;

	root = NULL;
	while (lngetword(word, MAXWORD) != EOF)
	{	if (isalpha(word[0]) && !shouldignore(word,banal,size_banal))
			root = craddtree(root, word,iline);
		else if (word[0] == '\n')
			iline++;
	}
	crtreeprint(root);
	return 0;
}
