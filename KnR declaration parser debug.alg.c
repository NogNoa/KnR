input="int (*daytab)[13]"
getttoken()
	*p=token[o200]
	c=d∈alnum
	token=*p="int"
	tokentype=NAME
datatype=token="int"
out=""
dcl()
	getttoken()
		c='('
		tokentype='('
	dirdcl()
		dcl()
			gettoken()
				*p="int"
				tokentype=c='*'
			ns=1
			gettoken()
				c=d∈alnum
				token=*p="daytab"
				tokentype=NAME
			dirdcl()
				name = "daytab"
				gettoken()
					tokentype=c=')'
			out = "pointer to"
		tokentype == ')'
		gettoken()
			c='['
			token=*p="13"
			tokentype = BRACKETS;
		out= " pointer to array 13 of"
		gettoken()
			tokentype=c='EOF'	
printf("syntax error\n")
printf("daytab:  pointer to array 13 of int\n")


