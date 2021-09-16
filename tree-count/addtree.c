// Ritchie, D. and Kernighan, W. (1988) p126

#include "tree_count.h"

struct tnode *talloc(void);
char *KnR_strdup(char *);


struct tnode *addtree(struct tnode *p, char *w)
{  /* addtree: add a node with w, at or below p */
	int cond;
	
	if (p == NULL)  /* a new word has arrived */
	{	p = talloc(); /* make a new node */
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

//original

struct htnode *htalloc(void);


struct htnode *haddtree(struct htnode *p, char* word, char *head, int h_len)
{  /* haddtree: add a node with w[0,h_len], at or below p */
	int cond;

	if (p == NULL)  
	{	p = htalloc(); 
		p->head = KnR_strdup(head);
		p->count = 1;
		p->left = p->right = NULL;
		p->headroot = addtree(p->headroot,word);
	} else if ((cond = strcmp(head, p->head)) == 0)
	{	p->count++; 
		p->headroot = addtree(p->headroot,word);
	} else if (cond < 0)
		p->left = haddtree(p->left, word, head, h_len);
	else 
		p->right = haddtree(p->right, word, head, h_len);
	return p;
}

int *lalloc(void);
void lappend(int*, int, int);

struct tnode *craddtree(struct tnode *p, char *w, int iline)
{  /* addtree: add a node with w, at or below p */
	int cond;
	
	if (p == NULL)  /* a new word has arrived */
	{	p = talloc(); /* make a new node */
		p->word = KnR_strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
		//p->pagi = lalloc();
		p->bookmark = 0;
		lappend(p->pagi,iline, p->bookmark);
	} else if ((cond = strcmp(w, p->word)) == 0)
	{	p->count++; /* repeated word */
		lappend(p->pagi,iline, p->bookmark);
	} else if (cond < 0) /* less than into left subtree */
		p->left = addtree(p->left, w);
	else /* greater than into right subtree */
		p->right = addtree(p->right, w);
	return p;
}

void lappend(int pagi[],int iline, int bookmark)
{
	if (bookmark > MAXLIST)
		return;
	else if (bookmark == 0 || pagi[bookmark-1] != iline)
		pagi[bookmark++] = iline;
}

_Bool shouldignore(char* word, char* ignore_me[], int ig_size)
{
	for(int k=0;k<ig_size;k++)
	{	if (strcmp(word, ignore_me[k]) == 0)
			return 1;
	}
	return 0;
}

