#include <stdio.h>

void shellsort(int v[], int n)
{ /* shellsort: sort v[0] to v[n-1] into increasing order */
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}

int main(){

	int TeXt[10] = (int) "bmkTDWmTqD";

	shellsort(TeXt, 10);
	TeXt = (char) TeXt;
	printf("%s", TeXt);
	
	return 0;
}
