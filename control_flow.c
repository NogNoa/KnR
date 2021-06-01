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
		default:
			s[j++] = c;break;
		}
	}
}

void descape(char s[], char t[])
{
	char c;
	int j = 0;
	for (int i=0;(c = t[i]) != 0;++i){
		switch(c){
		case '\\':
			switch (t[i]){
			case 'n':
				s[j++] = '\n';break;
			case 't':
				s[j++] = '\t';break;
			case '\\':
				s[j++] = '\\';break;
			default:
				s[j++] = '\\';s[j++] = t[i];break;
			}
			++i;break;
		default:
			s[j++] = c;break;
		}
	}
}
