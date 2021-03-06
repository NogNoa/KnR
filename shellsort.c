// Ritchie, D.M. and Kernighan, B.W. (1988) p57

#include <stdio.h>

void shellsort(int v[], int n)
{ /* shell-sort: sort v[0] to v[n-1] into increasing order */
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}

int main()
{
    char text[10] = "bmkTDWmTqD";
    int TeXt[10];

	for (int i;i<10;++i)
		TeXt[i] = (int) text[i];
	shellsort(TeXt, 10);
	for (int i;i<10;++i)
		text[i] = (char) TeXt[i];	
	printf("%s", text);
	
	return 0;
}
