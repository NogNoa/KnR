#include <ctype.h>
#include "tree_count.h"

#define MAXWORD 100

struct lnode *addlist(struct lnode *,struct lnode *, char *);
void listprint(struct lnode *);
int getword(char *, int); //from molon.lb.c


int main()
{ /* word frequency count */
	struct lnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addlist(root, root, word);
	if (root != NULL)	
	/*root itself is null placeholder, so we want to skip it, 
	but therefore we have to check it's initialised. */
		listprint(root->lrgr); 
	return 0;
}
