

def wide(l, st, en):
	interval = [zip(st,en)]
	interval.sort()

	merged = [interval[0]]
	for (s,e) in interval[1:]:
		if s > merged[-1][1]:
			merged.append((s,e))
		else:
			
