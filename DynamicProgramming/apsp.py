# dynamic programming book
# page 50
# section 2.2
# All-Pairs Shortest Paths Problem

#DPFE -> f(k, p, q) = 	min{ b(p, r) + f(k-1, r, q) }
#				      r -> {S}




b = [[1000,    3, 5   , 1000],
	 [1000, 1000, 1   , 8   ],
	 [1000, 2   , 1000, 5   ],
	 [1000, 1000, 1000, 1000]]


def apsp(k, p, q):
	if k == 0:
		return 0
	if p == q:
		return 1000

	for r in range(len(b)):
		apsp(k-1, r, q)
		newMin = b[p][r] + b[r][q]

		if b[p][q] > newMin:
			b[p][q] = newMin

for i in range(4):
	for j in range(4):
		apsp(4, i, j)


for i in b:
	print(i)



