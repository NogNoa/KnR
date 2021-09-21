input="Filster.csv"
stati[1]={.numeric=1}, stati[2]={.casefld=1}
nfield=4-2=2
nlines=11
KnR_qsort((char ***) linptr, 0, (nlines-1=10), stti)
	(left=0) < (right=10)
	swap((v=(char ***)linptr), 0, ((left+right)/2=5))
		temp := v[0] = pointer(line1,field1)
		