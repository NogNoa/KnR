// Ritchie, D.M. and Kernighan, B.W. (1988) p78

void swap(int v[], int i, int j)
{	/* swap: interchange v[i] and v[j] */

	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void KnR_qsort(int v[], int left, int right)
{	/* qsort: sort v[left]...v[right] into increasing order */

	int i, last;
	void swap(int v[], int i, int j);

	/* do nothing if array contains fewer than two elements */
	if (left >= right) 
		return;
	/* move partition elem to v[0] */
	swap(v, left, (left + right)/2); 
	last = left; 
	for (i = left + 1; i <= right; i++) /* partition */
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last); /* restore partition elem */
	KnR_qsort(v, left, last-1);
	KnR_qsort(v, last+1, right);
}
