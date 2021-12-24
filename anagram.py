

def factorial(a):
	b = 1
	for i in range(1, a+1):
		#print(i)
		b *= i

	return b


while(True):
	a = str(input())

	b = []

	lett = []
	p = []

	for i in range(len(a)):
		if not a[i] in lett:
			lett.append(a[i])
			p.append(0)

	for i in range(len(a)):
		for k in range(len(lett)):
			if a[i] == lett[k]:
				p[k]+=1



	fact = 1

	print(p)

	for i in range(len(p)):
		fact *= factorial(p[i])

	#print(factorial(3))

	print(factorial(len(a))// fact)






