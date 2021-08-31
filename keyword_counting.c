// Ritchie, D. and Kernighan, W. (1988) p119

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

struct key {
	char *word;
	int count;
} keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"double", 0,
	"int", 0,
	"struct", 0,
	"else", 0,
	"long", 0,
	"switch", 0,
	"enum", 0,
	"register", 0,
	"typedef", 0,
	"extern", 0,
	"return", 0,
	"union", 0,
	"float", 0,
	"short", 0,
	"for", 0,
	"signed", 0,
	"goto", 0,
	"sizeof", 0,
	"do", 0,
	"if", 0,
	"static", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

static const int NKEYS = sizeof(keytab)/sizeof(struct key);

int getword(char *, int); /* in molon.lb.c */
int binsearch(char *, struct key *, int);

int main()
{ /* count C keywords */
	int n;
	char word[MAXWORD];
	
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n",
			keytab[n].count, keytab[n].word);
	return 0;
}

int binsearch(char *word, struct key tab[], int n)
{ /* binsearch: find word in tab[0]...tab[n-1] */
	int cond;
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

