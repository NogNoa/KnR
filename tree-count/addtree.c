#include <stddef.h>

#include "tree_count.h"

struct tnode *talloc(void);
struct htnode *htalloc(void);
char *KnR_strdup(char *);


struct tnode *addtree(struct tnode *p, char *w)
{  /* addtree: add a node with w, at or below p */
	int cond;
	
	if (p == NULL) { /* a new word has arrived */
		p = talloc(); /* make a new node */
		p->word = KnR_strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++; /* repeated word */
	else if (cond < 0) /* less than into left subtree */
		p->left = addtree(p->left, w);
	else /* greater than into right subtree */
		p->right = addtree(p->right, w);
	return p;
}

struct htnode *haddtree(struct htnode *p, char *w, int h_len)
{  /* haddtree: add a node with w[0,h_len], at or below p */
	int cond;
	
	char *head = w;
	head[h_len]='\0';

	if (p == NULL) { 
		p = htalloc(); 
		p->head = KnR_strdup(head);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(head, p->head)) == 0)
		p->count++; 
	else if (cond < 0)
		p->left = haddtree(p->left, head, h_len);
	else 
		p->right = haddtree(p->right, head, h_len);
	return p;
}


void treeprint(struct tnode *p)
{  /* treeprint: in-order print of tree p */
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

void htreeprint(struct htnode *p)
{  /* treeprint: in-order print of tree p */
	if (p != NULL) {
		htreeprint(p->left);
		printf("%4d %s\n", p->count, p->head);
		htreeprint(p->right);
	}
}