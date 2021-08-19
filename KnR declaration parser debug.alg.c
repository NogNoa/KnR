input="(*daytab)[13]" 
getttoken()
	*p≔token[o200]
	c='('
	tokentype=PARENS
datatype=token=garbage
out=""
dcl()
	gettoken()
		*p=garbage
		tokentype=c=^' *^'
	ns=1
	gettoken()
		c=d∈alnum
		token=*p="daytab"
		tokentype=NAME
	dirdcl()
		name = "daytab"
		gettoken()
			c='['
			token=*p="13"
			tokentype = BRACKETS;
		out= " array 13 of"
		gettoken()
			tokentype=c=EOF	
	out=" array 13 of pointer to" 
	printf("daytab:  array 13 of pointer to ")


