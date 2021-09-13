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

struct tnode *talloc(void);
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


void treeprint(struct tnode *p)
{  /* treeprint: in-order print of tree p */
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

#include <stdlib.h>

struct tnode *talloc(void)
{  /* talloc: make a tnode */
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *KnR_strdup(char *s) 
{  /* make a duplicate of s */
	char *p;
	
	p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}
