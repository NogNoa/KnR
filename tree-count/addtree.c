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

void append(int*, int, int*);

struct tnode *craddtree(struct tnode *p, char *w, int iline)
{  /* addtree: add a node with w, at or below p */
	int cond;
	
	if (p == NULL)  /* a new word has arrived */
	{	p = talloc(); /* make a new node */
		p->word = KnR_strdup(w);
		p->left = p->right = NULL;
		p->bookmark = 0;
		append(p->lini,iline, &p->bookmark);
	} else if ((cond = strcmp(w, p->word)) == 0)
		append(p->lini,iline, &p->bookmark);
	else if (cond < 0) /* less than into left subtree */
		p->left = craddtree(p->left, w, iline);
	else /* greater than into right subtree */
		p->right = craddtree(p->right, w, iline);
	return p;
}

void append(int lini[],int iline, int *bookmark)
{
	if (*bookmark >= MAXLIST)
		return;
	else if (*bookmark == 0 || lini[*bookmark-1] != iline)
		lini[(*bookmark)++] = iline;
}

struct lnode *lalloc(void);
struct lnode *reshuffle(struct lnode *);

struct lnode *addlist(struct lnode *p, struct lnode *root, char *w)
{	struct lnode *q=p->lrgr;
	if (q == NULL)
	{	struct lnode *new;
		new= lalloc();
		new->word = KnR_strdup(w);
		new->count = 1;
		new->lrgr = root->lrgr;
		root->lrgr = new;
	} else if ((strcmp(w, q->word)) == 0)
	{	q->count++; 
		if (q->lrgr != NULL && q->count > q->lrgr->count)
			p = reshuffle(p);
	} else
		root = addlist(q, root, w);
	return root;
}

struct lnode *reshuffle(struct lnode *p)
{
	struct lnode *q=p->lrgr, 
				 *r=q->lrgr;
	
	q->lrgr = r->lrgr;
	r->lrgr = q;
	p->lrgr = r;

	if (q->lrgr != NULL && q->count > q->lrgr->count)
		r = reshuffle(r);

	return p;
}


_Bool shouldignore(char* word, char* ignore_me[], int ig_size)
{
	for(int k=0;k<ig_size;k++)
	{	if (strcmp(word, ignore_me[k]) == 0)
			return 1;
	}
	return 0;
}


