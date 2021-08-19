input="*daytab"
getttoken()
	*p=token[o200]
	tokentype=c=*
dirdcl(1)
	dcl(1)
		getttoken()
			token=*p="daytab"
			tokentype=NAME
		dirdcl(0)
			name="daytab"
			gettoken()
				tokentype=c='EOF'	
		out = " pointer to"
out = "\0pointer to" = ""
dcl(0)
	getttoken()
		tokentype=c='EOF'
	dirdcl(0)
		fprintf(stderr,"error: expected name or (dcl)\n");
printf("daytab:\n")


