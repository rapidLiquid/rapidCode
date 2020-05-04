

def cmap(funs, inp):
	def apply(o):
		for f in funs: o = f(o)
		return o
	for i in inp:
		yield apply(i)



def main():
	gen = cmap([lambda x : x * x, lambda x : x + x], [1,2,3,4])
	it = iter(gen)
	print(next(it))
	print(next(it))
	print(next(it))
	print(next(it))


if __name__ == '__main__':
	main()