#include <stdlib.h>
#include <string.h>

// Ritchie, D.M. and Kernighan, B.W. (1988) p128

struct nlist { /* table entry: */
	struct nlist *next; /* next entry in chain */
	char *name; /* defined name */
	char *defn; /* replacement text */
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */


static unsigned hash(char *s)
{  /* hash: form hash value for string s */
	unsigned hashval;
	
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	
	return hashval % HASHSIZE;
}


struct nlist *lookup(char *s)
{  /* lookup: look for s in hashtab */
	struct nlist *np;
	
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np; /* found */
	
	return NULL; /* not found */
}


struct nlist *install(char *name, char *defn)
{  /* install: put (name, defn) in hashtab */
	struct nlist *np;
	unsigned hashval;
	
	if ((np = lookup(name)) == NULL)  /* not found */
	{	np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else /* already there */
		free((void *) np->defn); /*free previous defn */
	
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	
	return np;
}

//original

int undef(char* name)
{
	struct nlist *np;

	if ((np = lookup(name)) == NULL)
		return 1;
	
	if (np->next !=NULL) //there is a continuation of the list we have to preserve
	{	unsigned hashval=hash(name);
		struct nlist *ante = hashtab[hashval];
		if (ante == np)
			hashtab[hashval] = np->next;
		else 
		{	for (; ante->next != np; ante = ante->next)
				;
			ante->next = np->next;
		}
	}
	free(np); np = NULL;
	return 0;
}
/*
#include <stdio.h>

int main()
{
	struct nlist *p1 = install("IN","1");
	struct nlist *p2 = install("OUT","2");
	struct nlist *p3 = install("IN","3");
	undef("OUT");
	printf("%s: %s\n",p2->name, p2->defn);
	printf("hashtab[hash(IN)]->next = %ld \nhashtab[hash(OUT)]->next = %ld\n",(long) hashtab[hash("IN")]->next, (long) hashtab[hash("OUT")]->next);
	printf("p1->next = %ld \np2->next = %ld\n",(long) p1->next, (long) p2->next);
	return 0;
}
*/
