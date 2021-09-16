// Ritchie, D. and Kernighan, W. (1988) p127

#include "tree_count.h"


struct tnode *talloc(void)
{  /* talloc: make a tnode */
	return (struct tnode *) malloc(sizeof(struct tnode));
}

struct htnode *htalloc(void)
{  /* htalloc: make a htnode */
	return (struct htnode *) malloc(sizeof(struct htnode));
}

char *KnR_strdup(char *s) 
{  /* make a duplicate of s */
	char *p;
	
	p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}
