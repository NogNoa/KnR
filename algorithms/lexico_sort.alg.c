input:FILE "Filters.csv"
argv= {"lexico_sort.c","-s,", "-nrf", "-r"}
argc = 4
lineptr = {{"",...}[512],...}[5120]
nfield:=1
argv[1] = "-s,"
argv[1][0] = '-'
argv[1][1]= 's'
nfield := argc-2 = 2
dlimit := argv[1][2] = ','
argv+= (argc - 1 = 3) = {"-r"}
nf:=2
--nf:=1 >=0
*argv[0] = *"-nrf" = '-' 
stt:=&stti[nf]=&stti[1]
*stt=stti[1]
*stt = {0,0,0,0}
c:= *++(argv[0]) = *++"-r" = *"r"='r'
(stt->reverse = 0) |= ((c == 'r') = 1) = 1
*stt = {0,1,0,1}
--argv := {"-nrf", "-r"}
--nf := 0 >= 0
*argv[0] = '-' 
stt:=&stti[nf]=&stti[0]
c := *++(argv[0]) = *++"-nrf" = *"nrf" = 'n'
*stt := {1,1,1,0} 
readlines(linptr,MAXLINE, nfield=2, buffer)
	nline=0
	line = "Name,Case,Whole Word,Path,Diacritics,Regex,Search,Macro,Key\n"
	len = 60
	p+=(len+1 =61) = "...\0..."[512-60=454] != NULL
	line[len] = '\n' := '\0'
	p := line
	*linptr[nline] = *linptr[0] = *{"",...}[512] = ""
	*linptr[nline] := p = line
	linptr = {{line,"",...}[512],...}[5120]
	fieldseperate(lineptr[nline++]=, nfield=2, p)
		fieldptr:=linptr[nline] = {line,"",...}[512]
		ifield=1
		pc=*fieldptr=*{line,"",...}[512]=line
		*pc = 'N' != (dlimit=',')
		...
		pc =",Case,Whole Word,Path,Diacritics,Regex,Search,Macro,Key\0"
		*pc = ',' := '\0'
		pc =""
		fieldptr = {"Name","",...}[512]
		(fielptr[ifield++] = "") := pc+1 =  "Case,Whole Word,Path,Diacritics,Regex,Search,Macro,Key\0" 
		fieldptr = {"Name","Case,Whole Word,Path,Diacritics,Regex,Search,Macro,Key\0",...}[512]
		pc++ := fieldptr[1]
		
