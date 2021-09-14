// Ritchie, D. and Kernighan, W. (1988) p125

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

static struct tnode { /* the tree node: */
	char *word; /* points to the text */
	int count; /* number of occurrences */
	struct tnode *left; /* left child */
	struct tnode *right; /* right child */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int); //from molon.lb.c

int main()
{ /* word frequency count */
	struct tnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}
