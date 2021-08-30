/* 386sx solution */ 
input.len=MAXLINE-1
getline()
	s[0,lim-2]=input[0,lim-2]
	i=lim-2
	c=='\n'
	s[lim-2]='\n'
	i=lim-1
	s[lim-1]='\0'
	return input.len
len = input.len > 0
line = input
line[MAXLINE-2] == '\n'
getmore == 0
(max = 0) < len
max = len
longest = line
max >0
printf(input)
printf("len = {max}\n")

input.len=MAXLINE
getline()
	s[0,lim-1]=input[0,lim-1]
	i=lim-1
	c=='\n'
	s[lim-1]='\n'
	i=lim
	s[lim]='\0'
	return input.len
len = input.len > 0
line = input
line[MAXLINE-1] == '\n'
getmore == 0
(max = 0) < len
max = len
longest = line
max >0
printf(input)
printf("len = {max}\n")

input.len=MAXLINE+1
getline()
	s[0,lim-1]=input[0,MAXLINE-1]
	i=lim-1
	c!='\n'
	s[lim-1]='\0'
	return input.len-2
len = MAXLINE-1 > 0
line = input[0,len]
line[MAXLINE-2] != '\n'
getmore == 0
temp = line
prevmax = MAXLINE-1
(max = 0) < prevmax
max = prevmax
getmore = 1
getline()
	s[0,1]=input[MAXLINE-1,MAXLINE]
	i=1
	c='\n'
	s[1]= '\n'
	i=2
	s[2] = '\0'
	return 2
rem.len=2
len = 2 > 0
line = input[MAXLINE-1,MAXLINE + 1]
line[1] == '\n'
getmore == 1
(max = prevmax = MAXLINE -1) < (prevmax + len = MAXLINE +1)
max = prevmax + len = MAXLINE +1
longest = temp = input[0,MAXLINE-1]
longest[MAXLINE - 2] = '\n'
longest == input[0,MAXLINE -2] "\n"
getmore = 0
(max = MAXLINE +1 = 21) > 0
printf(longest)
printf("len = {max}\n")

input.len = 2*MAXLINE + 1
getline()
	s[0,lim-1]=input[0,lim-1]
	i=lim-1
	c!='\n'
	s[lim-1]='\0'
	return MAXLINE - 1
len = MAXLINE-1 > 0
line = input[0,len]
line[MAXLINE-2] != '\n'
getmore == 0
temp = line
prevmax = MAXLINE-1
(max = 0) < prevmax
max = prevmax
getmore = 1
getline()
	s[0,lim-1]=input[MAXLINE-1,2*MAXLINE-2]
	i=lim-1
	c= input[2*MAXLINE-2] != '\n'
	s[lim-1] = '\0'
	return MAXLINE-1
len = MAXLINE-1 > 0
line = input[MAXLINE-1,2*MAXLINE-2]
line[MAXLINE -2] != '\n'
getmore == 1
(prevmax = MAXLINE -1) += len 
prevmax = 2*MAXLINE -2
(max = MAXLINE -1) < (prevmax = 2 * MAXLINE -2)
max = prevmax
getmore = 1
getline()
	s[0,2]=input[2*MAXLINE-2,2*MAXLINE]
	i=2
	c='\n'
	s[2]= '\n'
	i=3
	s[3] = '\0'
	return 3
len = 3
line = input[2*MAXLINE-2,2*MAXLINE+1]
line[2]== '\n'
getmore == 1
(max = prevmax = 2 * MAXLINE -2) < (prevmax + len = 2 * MAXLINE +1)
max = prevmax + len = 2 * MAXLINE +1
longest = temp = input[0,MAXLINE-1]
longest[MAXLINE - 2] = '\n'
longest == input[0,MAXLINE -2] "\n"
getmore = 0
(max = 2 * MAXLINE +1 = 41) > 0
printf(longest)
printf("len = {max}\n")
