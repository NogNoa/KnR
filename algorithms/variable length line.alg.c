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

input1.len=MAXLINE+1
getline()
	s[0,lim-1]=input1[0,lim-1]
	i=lim-1
	c!='\n'
	s[lim-1]='\0'
	return input1.len-2
len = MAXLINE-1 > 0
line = input1[0,len]
line[MAXLINE-2] != '\n'
getmore == 0
temp = line
prevmax = MAXLINE-1
(max = 0) < prevmax
max = prevmax
getmore = 1
input2.len=MAXLINE
len = MAXLINE > 0
line = input2
line[MAXLINE -1] == '\n'
getmore == 1
(max = prevmax = MAXLINE -1) < (prevmax + len = 2 * MAXLINE -1)
max = prevmax + len = 2 * MAXLINE -1
longest = temp = input1[0,MAXLINE-1]
longest[MAXLINE - 2] = '\n'
longest == input[0,MAXLINE -2] "\n"
getmore = 0
(max = 2 * MAXLINE -1 = 39) > 0
printf(longest)
printf("len = {max}\n")

