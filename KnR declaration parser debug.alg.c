input="*daytab"
getttoken()
	*p=token[o200]
	tokentype=c=*
datatype=token=""
out=""
dcl()
	getttoken()
		token=*p='daytab'
		tokentype=NAME
	dirdcl()
		name = 'daytab'
		gettoken()
			tokentype=c='EOF'	
printf("daytab:\n")


