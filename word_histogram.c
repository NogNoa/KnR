#include <stdio.h>
#define MXWRD 0x20
static inline _Bool unblank(char c)
{
	return c != ' ' && c != '\n' && c != '\t';
}


int measure(int hest[]);
void expose_hor(int hest[], int mxlen);
void mkrow_len(char row[], int len);
void expose_ver(int hest[], int mxcnt);
void mkrow_cnt(char row[], int hest[], int cnt, int mxlen);

int main()
{
	int mxlen, hest[(MXWRD)];

	mxlen = measure(hest);
    
	expose_ver(hest, mxlen);

	return 0;
}

int mxcnt = 0;

int measure(int hest[])
{
	int i;
	char c,prev='\n';
	int len = 0;
    int mxlen = 0;

	for (i = 0; i<(MXWRD); ++i)
		hest[i] = 0;

	while ((c = getchar()) != EOF) {
		if (unblank(c)){
			++len;
		}
		else if (unblank(prev)){
			++hest[len];
			if (len > mxlen)
                mxlen = len;
            if (hest[len] > mxcnt)
            	mxcnt = hest[len];
			len = 0;
		}
		prev=c;
	}
    return mxlen;
}

void expose_hor(int hest[], int mxlen)
{
	int i;
	//char plus;
	char row[0x300];

	for (i=1; i<=mxlen; ++i){
		mkrow_len(row, hest[i]);
		printf("%2d  %s\n",i, row);
	}
}

void mkrow_len(char row[], int len)
{
	int j;
	for (j=0; j<len; ++j)
		row[j] ='|';
	row[j] = '\0';
}

void expose_ver(int hest[], int mxlen)
{
	char row[0x300];

	for (int i=mxcnt; i>0;--i)
	{	mkrow_cnt(row, hest, i, mxlen);
		printf("%2d %s\n",i, row);
	}
	printf("   ");
	for (int i=1;i<=mxlen;++i)
		printf("%3d",i);
	putchar('\n');
}

void mkrow_cnt(char row[], int hest[], int cnt, int mxlen)
{
	int i,j=2;

	for (i=1;i<=mxlen;i++,j+=3)
		row[j-2]=row[j-1]=' ';
	{	if (hest[i]>=cnt)
			row[j]='|';
		else
			row[j]=' ';
	}
	row[j-2]='\0';
}