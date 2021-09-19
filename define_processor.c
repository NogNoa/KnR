#include <stdio.h>
#include <string.h>

#define DIR_S 0200
#define FLD_S 040

char get_directive(char *direct, int lim);
void seperate(char *str, char sep, int lim, int vacount, ...);
struct nlist *install(char *name, char *defn);


int main(int argc, char** argv)
{
	if (argc>1)
		stdin=fopen(argv[1],"r");
	FILE *codex=stdin;

	char direct[DIR_S];

	struct nlist { /* table entry: */
		struct nlist *next; /* next entry in chain */
		char *name; /* defined name */
		char *defn; /* replacement text */
	};

	char back;
	while( (back=get_directive(direct, DIR_S)) != EOF)
	{	if (back == '\0')
			printf("weird: %s",direct);
		char cmd[FLD_S], name[FLD_S], defn[FLD_S];
		seperate(direct, ' ', FLD_S, 3, cmd, name, defn);
		if (strcmp(cmd,"define") == 0)
			install(name, defn);
	}
	fseek(codex, 0, SEEK_SET);

}

/* problem: I need to look throu the same file twice as stdin */
