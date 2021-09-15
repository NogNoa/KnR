#include <ctype.h>
#include "tree_count.h"

#define MAXWORD 0200

struct tnode *addtree(struct tnode *p, char *);
struct htnode *haddtree(struct htnode *, char *, int);
void htreeprint(struct htnode *);
char *KnR_strdup(char *);
char ig_getword(char *, int); //from molon.lb.c
_Bool iskeyword(char*);

int main()
{ /* word frequency count */
	struct htnode *root;
	char word[MAXWORD];
	
	int h_len=6;

	root = NULL;
	while (ig_getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]) && !iskeyword(word))
		{	char *head = KnR_strdup(word);
			head[h_len]='\0';
			root = haddtree(root, head, h_len);
		}
	htreeprint(root);
	return 0;
}

static char* keywords[] = {
	"auto",
	"break",
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
	"static",
	"unsigned",
	"void",
	"volatile",
	"while",
};

_Bool iskeyword(char* word)
{
	for(int k=0;k<(sizeof keywords / sizeof *keywords);k++)
	{	if (strcmp(word, keywords[k]) == 0)
			return 1;
	}
	return 0;
}

/* is cword? (starting with alpha or _ continue with them or number) (n-mind getword already does this, and cwords can't start with _)
v is keyword? 
v tree where words are identical if 6 chars are identical
 another tree inside each node not using the count
v use ig_getword
*/
