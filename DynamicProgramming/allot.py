# dynamic programming book
# page 49
# section 2.1
# Optimal Allotment Problem

#DPFE -> f(k, m) = 		min{ C(k, d) + f(k+1, m-d) }
#				 d -> {0, ..., m}

costs = [[1000, 1.0, 0.8, 0.4, 0.0],
		 [1000, 1.0, 0.5, 0.0, 0.0],
		 [1000, 1.0, 0.6, 0.3, 0.0]]


def allot(k, m, path = []):
	if k > N and m >= 0:
		return 0, path

	miin = 10000
	bestPath = []
	for d in range(m+1):
		tempPath = list(path)
		tempPath.append(d)

		newCost, newPath = allot(k+1, m-d, tempPath)
		newCost += costs[k-1][d]

		if newCost < miin:
			miin = newCost
			bestPath = newPath
		
	return miin, bestPath

N = 3
M = 4
print( allot(1, M) )
