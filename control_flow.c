void escape(char s[], char t[])
{
	char c;
	int j = 0;
	for (int i=0;(c = t[i]) != 0;++i){
		if (c == '\n'){
			s[j++] = '\\'; s[j++] = 'n';
		}
		else if (c == '\t'){
			s[j++] = '\\'; s[j++] = 't';
		}
		else
			s[j++] = c;
	}
}

void descape(char s[], char t[])
{
	char c;
	int j = 0;
	for (int i=0;(c = t[i]) != 0;++i){
		if (c == '\\'){
			if (t[i] == 'n')
				s[j++] = '\n';
			else if (t[i] == 't')
				s[j++] = '\t';
			else if (t[i] == '\\')
				s[j++] = '\\';
			else{
				s[j++] = '\\';s[j++] = t[i];
			}
			++i;
		}
		else
			s[j++] = c;
	}
}