#include <ctype.h>
#include "tree_count.h"

#define MAXWORD 100

struct lnode *addlist(struct lnode *,struct lnode *, char *);
void listprint(struct lnode *);
int getword(char *, int); //from molon.lb.c
struct lnode *lalloc(void);


int main()
{ /* word frequency count */
	struct lnode *root;
	char word[MAXWORD];
	
	root = lalloc();
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addlist(root, root, word);
	listprint(root->lrgr); /*root itself is null placeholder, so we want to skip it */
	return 0;
}
