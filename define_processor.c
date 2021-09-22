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

char* nameary[LIN_S];
int NP=0;

/*external*/
char get_directive(char *direct, size_t lim);
void seperate(char *str, char sep, size_t lim, int vacount, ...);
struct nlist *install(char *name, char *defn);

void table_make(void)
{
	char direct[LIN_S];
	
	while(get_directive(direct, LIN_S) != '\0')
	{	char cmd[FLD_S], name[FLD_S], defn[FLD_S];
		struct nlist *nom_ptr;
		seperate(direct, ' ', FLD_S, 3, cmd, name, defn);
		if (strcmp(cmd,"define") == 0)
		{	nom_ptr = install(name, defn);
			nameary[NP++] = nom_ptr->name; 
		}
	}
}


/*external*/
struct nlist *lookup(char *s);
char uni_getword(char *word, size_t lim);

_Bool namecompare(char* token, int iname)
{
	char *name = nameary[iname];
	token++, name++;

	for (;*name != '\0';token++,name++)
	{	
		if (*token == '\0')
			*token = getchar();
		if(*token != *name)
			break;
	}
	*++token = '\0'; 
	if (*name == '\0')
		return 1;
	else
		return 0;
}

void text_process(void)
{
	char token[FLD_S]={0};
	struct nlist *nom_ptr;
	_Bool found;

	while ((*token = getchar()) != EOF)
	{	for (int i=0;i<NP;i++)
			if (( found = (*token == *nameary[i] && namecompare(token, i)) ))
			{ 	nom_ptr = lookup(nameary[i]);
				printf("%s",nom_ptr->defn);
				break;
			}
		if (!found)
			printf("%s",token);
		memset(token,0,FLD_S);
	}
}

/* somewhere between the two functions in main a char is lost (namely the / that start line 8) */
