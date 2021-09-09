// Ritchie, D. and Kernighan, W. (1988) p97
// Ritchie, D. and Kernighan, W. (1988) p106

#include "KnR_getline.h"
#include <ctype.h>
#define MAXLINES 5120 /* max #lines to be sorted */
#define MAXLEN 1024 /* max length of any input line */

char *lineptr[MAXLINES][MAXLEN/2]; /* pointers to text lines divided to fields*/
int nfield=1;

static struct state{
_Bool numeric; /* 1 if numeric sort */
_Bool reverse; /* 1 if reverse sort */
_Bool casefld; /* 1 if case insensitive sort */
_Bool dircord; /* 1 if directory order sort */
} linstt ={0,0,0,0}, fieldstt={0,0,0,0};

int readlines(char *lineptr[][512], int nlines, char dlimit, char *snglptr);
void fieldseperate(char *fieldptr[], char dlimit);
void writelines(char *lineptr[][512], int nlines, char dlimit);
void set_state(char *arg, struct state *stt)
void KnR_qsort(void *lineptr[], int left, int right, int (*cmp)(void *, void *, void *));
int numcmp(char *s1, char *s2, struct state *);
int astrcmp (char *s1, char *s2);
int lexcmp(char *cs,char *ct, struct state *stt);
int fieldcmp (char fp1[], char fp2[], struct state stti[]);

int main(int argc, char *argv[])
{	/* sort input lines */
	int nlines; /* number of input lines re'd */
	char buffer[MAXLEN];

	//stdin = fopen("a.txt", "r");
	char dlimit = ' ';

	if (argc > 2)
		set_state(arg[2], fieldstt)
	if (argc > 1 && (arg=argv[1])[0] == '-')
		set_state(arg[1], linstt)
	if ((nlines = readlines(lineptr, MAXLINES,dlimit,buffer)) >= 0) 
	{	KnR_qsort((void**) lineptr, 0, nlines-1,
		(int (*)(void*,void*,void*))(linstt.numeric ? numcmp : lexcmp));
		writelines(lineptr, nlines, dlimit);
		return 0;
	} 
	else 
	{	printf("error: input too big and scary to sort\n");
		return 1;
	}
}

void set_state(char *arg, struct state *stt)
{
	if (*arg == '-')
	{	char c;
		while ((c = *++arg ))
		{	stt.numeric |= (c == 'n');
			stt.reverse |= (c == 'r');
			stt.casefld |= (c == 'f');
			stt.dircord |= (c == 'd');
		}
	}
}

int astrcmp (char* s1, char* s2)
{
	return strcmp(s1, s2);
}

int numcmp(char *s1, char *s2, struct state *p)
{	/* numcmp: compare s1 and s2 numerically */
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

int lexcmp(char *cs,char *ct, struct state *stt)
{ /* compare string cs to string ct, disregarding case; return <0 if
     cs<ct, 0 if cs==ct, or >0 if cs>ct. */
	char ccs=1, cct=1;
	for (;ccs == cct && cct;cs++,ct++)
	{	ccs=*cs; cct=*ct;
		if (stt->casefld)
		{	ccs=tolower(ccs);
			cct=tolower(cct);
		}
		if (stt->dircord)
		{	ccs = (isspace(ccs) || isalnum(ccs)) ? ccs : '!';
			cct = (isspace(cct) || isalnum(cct)) ? cct : '!';
		}
	}
	return ccs-cct;
}

int readlines(char *lineptr[][512], int maxlines, char dlimit, char *p)
{	/* readlines: read input lines */
	int len, nline;
	char line[MAXLEN];
	
	for (nline = 0; (len = ptr_KnR_getline(line, MAXLEN)) > 0;nline++)
	{	if (nline >= maxlines || (p+=len+1) == NULL)
			return -1;
		else 
		{	if (line[len-1] == '\r')
				line[len-1] = '\0';
			else if (line[len] == '\n')
				line[len] =  '\0'; /* delete newline */
			strcpy(p, line);
			*lineptr[nline] = p;
			fieldseperate(lineptr[nline],dlimit);
		}
	}
	return nline;
}

void fieldseperate(char *fieldptr[], char dlimit)
{	/* Takes fieldptr,a line of fields , the whole text of the line is in 
	the first field. The function seperate the text to the fields by 
	terminating each of them at each instance of the delimiter, 
	and referancing the next field to the next character */
	int ifield=1;
	for(char *pc=*fieldptr;*pc != '\0' && ifield < MAXLEN/2;pc++)
		if (*pc == dlimit)
		{	*pc = '\0';
			fieldptr[ifield++] = pc+1;
		}
}


void writelines(char *lineptr[][512], int nlines, char dlimit)
{ /* writelines: write output lines */
	for (int l = 0; l < nlines; l++)
	{	for (int f=0;lineptr[l][f] != NULL;f++)
			printf("%s%c",lineptr[l][f],dlimit);
		putchar('\n');
	}
}


void swap(void *v[], int i, int j)
{ /* swap: interchange v[i] and v[j] */
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void swaplines(void *v[], int linei, int linej)
	while (*++(v[linei]) && *++(v[linej]))
	{	

	}

void KnR_qsort(void *v[], int left, int right,
	int (*cmp)(void *, void *, void *))
{ /* qsort: sort v[left]...v[right] into increasing order */
	int i, last;
	
	void swap(void *v[], int i, int j);

	if (left >= right) /* do nothing if array contains */
		return; 	  /* fewer than two elements      */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (((*cmp)(v[i], v[left],&linstt) < 0) ^ linstt.reverse)
			swap(v, ++last, i);
	swap(v, left, last);
	KnR_qsort(v,   left, last-1, cmp);
	KnR_qsort(v, last+1,  right, cmp);
}

/*
todo:  v	take argument for delimiter
	  v	make state for each field
	  v	seperate each line to fields
	  v	sort by fields
	  v	take different arguments for each field
problem: I'm only switching field 0 of each line since I'm useing pointers
*/


