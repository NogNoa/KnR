// Ritchie, D. and Kernighan, W. (1988) p54

int KnR_binsearch(int x, int v[], int n)
{ /* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;
	}
	return -1; /* no match */
}

int binsearch(int x, int v[], int n)
{ /* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low < high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid + 1;
		else
			low = mid + 1;
	}
	if (low == high)
		return low; //match
	else 
		return -1; // no match
}
/*
assume   high = (low+high)/2 + 1; x = v[(low+high)/2] 
happen	{high/2 = low/2 + 1
	   	 high = low + 2}
than    {(low < high)
	       mid = high - 1
	       x >= v[mid]
	       low = mid + 1 = high
	     (low >= high)
	     ...}
than 	 (x == v[mid]) iff (low == high)
*/


//Original

void escape(char s[], char t[])
{
	char c;
	int j = 0;
	for (int i=0;(c = t[i]) != 0;++i){
		switch(c){
		case '\n':
			s[j++] = '\\'; s[j++] = 'n';break;
		case '\t':
			s[j++] = '\\'; s[j++] = 't';break;
		case '\b':
			s[j++] = '\\'; s[j++] = 'b';break;
		case '\v':
			s[j++] = '\\'; s[j++] = 'v';break;
		case '\f':
			s[j++] = '\\'; s[j++] = 'f';break;
		case '\r':
			s[j++] = '\\'; s[j++] = 'r';break;
		case '\'':
		case '\"':
		case '\\':
			s[j++] = '\\'; s[j++] = c;break;
		default:
			s[j++] = c;break;
		}
	}
	s[j] = 0;
}

void descape(char s[], char t[])
{
	char c;
	int j = 0;
	for (int i=0;(c = t[i]) != 0;++i){
		switch(c){
		case '\\':
			switch (t[++i]){
			case 'n':
				s[j++] = '\n';break;
			case 't':
				s[j++] = '\t';break;
			case 'b':
				s[j++] = '\b';break;
			case 'v':
				s[j++] = '\v';break;
			case 'f':
				s[j++] = '\f';break;
			case 'r':
				s[j++] = '\r';break;
			case '\'':
			case '\"':
			case '\\':
				s[j++] = t[i];break;
			default:
				s[j++] = '\\';s[j++] = t[i];break;
			}
			break;
		default:
			s[j++] = c;break;
		}
	}
	s[j] = 0;
}
