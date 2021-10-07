in = [7,8,5,9,4,3,9,6]
quicksort(in, 0, 7)
	0 < 7
	middle := split(in, 0, 7)
		part := in[0] = 7
		0 < 8 && part !<= (in[7]=6)
		in[0] := in[7] = 6
		low:=1
		[6,8,5,9,4,3,9,6]
		1 < 8 && (in[1] = 8) !<= 7
		a[7] := (in[1]=8)
		high := 6
		[6,3,5,9,4,3,9,8]

		(part =7) <= (in[6]=9)
		high:=5
		7 !<= (in[5]=3)
		in[1] := in[5] = 3
		low:=2
		[6,3,5,9,4,3,9,8]
		(in[2] = 5) <= 7
		low:=3
		(in[3] = 9) !<= 7
		a[5] := (in[3]=9)
		high = 4
		[6,3,5,9,4,9,9,8]

		(part =7) !<= (in[4]=4)
		in[3] := (in[4] = 4)
		low :=4
		[6,3,5,4,4,9,9,8]
		(low=4) !< (high=4)

		a[4]:=part = 7
		[6,3,5,4,7,9,9,8]
		return 4
	[7,8,5,9,4,3,9,6] -> [6,3,5,4,7,9,9,8]
	middle := 4
	quicksort(in, 0, 3)
		middle = split(in, 0, 3)
			[6,3,5,4,...]
			part := in[0] = 6
			part = 6 !<= a[3] = 4
			in[low=0] := a[high=3] = 4
			low:=1
			[4,3,5,4,...]
			in[low=1]=3 <= 6
			low:=2
			in[low=2]=5 <= 6
			low:=3
			low !< high
			a[high=3] := part =6
			[4,3,5,6,...]
			return 3
		middle=3
		quicksort(in,0,2)
			middle := split(in,0,2)
				[4,3,5,...]
				part = 4
				4 < a[high=2] = 5
				high:=1
				4 !< in[1] = 3
				in[0] := 3
				low= 1
				[3,3,5,...]
				low= 1 !< high=1
				a[1]:=4
				[3,4,5,...]
				return 1
			middle =1
			quicksort(in,0,0)
				0 >= 0
				return void
			quicksort(in,2,2)
		quicksort(in,4,3)
	quicksort(in,5,7)
		middle := split(in,5,7)
			[...,9,9,8]
			part := 9
			9 !<= 8
			a[low=5] := 8
			low:=6
			[...,8,9,8]
			a[6]=9 <= 9
			low:=7
			low !<high
			a[7] := 9
			[...,8,9,9]
			return 7
		middle = 7
		quicksort(in,5,6)
			middle :=split(in,5,6)
				[...,8,9,...]
				part = 8
				8 <= 9
				high:=5
				low !<high
				in[5] = 8
				[...,8,9,...]
				return 5
			middle = 5
			quicksort(in,5,4)
			quicksort(in,6,6)
		quicksort(in,8,7)
[3,4,5,6,7,8,9,9]


middle :=split(in,0,0)
	[3,...]
	part := 3
	0 !<0
	in[0] := 3
	return 0
middle = 0