#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode { /* the tree node: */
	char *word; /* points to the text */
	int count; /* number of occurrences */
	struct tnode *left; /* left child */
	struct tnode *right; /* right child */
};

struct wordhead {// starting charecters of words
	char *head; // the string that make the wordhead
	int count; 
	char tnode *headroot; // the root of a tree of only the words starting with this head
}
