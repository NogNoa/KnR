// Ritchie, D.M. and Kernighan, B.W. (1988) p125

#include <ctype.h>
#include "tree_count.h"

#define MAXWORD 100

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

