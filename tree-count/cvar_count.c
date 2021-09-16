#include <ctype.h>
#include "tree_count.h"

#define MAXWORD 0200

struct htnode *haddtree(struct htnode *, char *, char*, int);
void htreeprint(struct htnode *);
char ig_getword(char *, int); //from molon.lb.c
_Bool shouldignore(char* word, const char* ignore_me[], int);

static const char* keywords[] = {
	"auto",
	"break",
	"Bool",
	"case",
	"char",
	"const",
	"continue",
	"default",
	"double",
	"int",
	"struct",
	"else",
	"long",
	"switch",
	"enum",
	"register",
	"typedef",
	"extern",
	"return",
	"union",
	"float",
	"short",
	"for",
	"signed",
	"goto",
	"sizeof",
	"do",
	"if",
	"main",
	"static",
	"unsigned",
	"void",
	"volatile",
	"while",
};


int main(int argc, char** argv)
{ /* word frequency count */
	int h_len;
	if (argc>1)
	{	if((h_len=atoi(argv[1])) > 0)
			;
		else
			h_len=6;
	}
	char word[MAXWORD];
	char head[h_len];
	const int size_keywords = sizeof keywords / sizeof *keywords;
	struct htnode *root;

	root = NULL;
	while (ig_getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]) && !shouldignore(word,keywords,size_keywords))
		{	strncpy(head, word, h_len);
			root = haddtree(root, word, head, h_len);
		}
	htreeprint(root);
	return 0;
}

/* v is cword? (starting with alpha or _ continue with them or number) (n-mind getword already does this, and cwords can't start with _)
v is keyword? 
v tree where words are identical if 6 chars are identical
v another tree inside each node not using the count
v use ig_getword
*/
