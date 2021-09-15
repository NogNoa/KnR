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

#include <string.h>

static char* keywords[] = {
	"auto",
	"break",
	"case",
	"char",
	"const",
	"continue",
	"default",
	"double",
	"int",
	"struct",
	"else",
	"long",
	"switch",
	"enum",
	"register",
	"typedef",
	"extern",
	"return",
	"union",
	"float",
	"short",
	"for",
	"signed",
	"goto",
	"sizeof",
	"do",
	"if",
	"static",
	"unsigned",
	"void",
	"volatile",
	"while",
};

_Bool iskeyword(char* word)
{
	for(int k=0;k<(sizeof keywords / sizeof *keywords);k++)
	{	if (strcmp(word, keywords[k]) == 0)
			return 1
	}
	return 0
}

/* is cword? (starting with alpha or _ continue with them or number) (n-mind getword already does this, and cwords can't start with _)
v is keyword? 
 create a regular word tree
 generate from that tree a tree that count only the wordhead and point the first word with that head
  use ig_getword
*/
