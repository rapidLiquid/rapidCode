t = int(input())

for _ in range(t):
	n = int(input())
	if n == 1: print("-1")
	else:
		s = ""
		for i in range(n-1):
			s += '3'
		s += '8'
		print(s)
