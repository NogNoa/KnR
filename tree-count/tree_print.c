#include "tree_count.h"

// Ritchie, D.M. and Kernighan, B.W. (1988) p126

void treeprint(struct tnode *p)
{  /* treeprint: in-order print of tree p */
	if (p != NULL) 
	{	treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

//original

void tree_line_print(struct tnode *p)
{  /* tree_line_print: in-order print of tree p on a line */
	if (p != NULL) 
	{	tree_line_print(p->left);
		printf("%s ", p->word);
		tree_line_print(p->right);
	}
}

void htreeprint(struct htnode *p)
{  /* htreeprint: print a wordhead and all it's words */
	if (p != NULL) 
	{	htreeprint(p->left);
		printf("%4d %s: ", p->count, p->head);
		tree_line_print(p->headroot);
		putchar('\n');
		htreeprint(p->right);
	}
}

void int_line_print(int *n)
{	for(;*n;n++)
		printf("%d ",*n);
	putchar('\n');
}

void crtreeprint(struct tnode *p)
{  /* treeprint: in-order print of tree p */
	if (p != NULL) 
	{	crtreeprint(p->left);
		printf("%s: ", p->word);
		int_line_print(p->lini);
		crtreeprint(p->right);
	}
}

void reverse_treeprint(struct tnode *p)
{  /* treeprint: in-order print of tree p */
	if (p != NULL) 
	{	reverse_treeprint(p->right);
		printf("%4d %s\n", p->count, p->word);
		reverse_treeprint(p->left);
	}
}

void listprint(struct lnode *p)
{  /* treeprint: in-order print of tree p */
	if (p != NULL) 
	{	listprint(p->lrgr);
		printf("%4d %s\n", p->count, p->word);
	}
}
