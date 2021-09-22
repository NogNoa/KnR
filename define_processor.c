#include <stdio.h>
#include <string.h>

#define LIN_S 0200
#define FLD_S 040


/*local*/
void table_make(void);
void text_process(void);

int main(int argc, char** argv)
{
	if (argc>1)
		stdin=fopen(argv[1],"r");

	table_make();
	text_process();
}

struct nlist 
	{ /* table entry: */
		struct nlist *next; /* next entry in chain */
		char *name; /* defined name */
		char *defn; /* replacement text */
	};

/*external*/
char get_directive(char *direct, int lim);
void seperate(char *str, char sep, int lim, int vacount, ...);
struct nlist *install(char *name, char *defn);

void table_make(void)
{
	char direct[LIN_S];
	
	while(get_directive(direct, LIN_S) != '\0')
	{	char cmd[FLD_S], name[FLD_S], defn[FLD_S];
		seperate(direct, ' ', FLD_S, 3, cmd, name, defn);
		if (strcmp(cmd,"define") == 0)
			install(name, defn);
	}
}


/*external*/
struct nlist *lookup(char *s);
char uni_getword(char *word, int lim);

void text_process(void)
{
	char token[FLD_S], c;
	struct nlist *nom_ptr;

	while ((c = uni_getword(token, FLD_S)) != EOF)
	{	if (( nom_ptr = lookup(token) ) != NULL)
			printf("%s",nom_ptr->defn);
		else
			printf("%s",token);
	}
}

/*problem: we need to replace tokens also when they are not surrondered by space */
