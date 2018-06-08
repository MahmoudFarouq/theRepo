

n = 999999
maxc = 0
maxi = 0
for i in range(n, 1, -1):
	counter = 0
	ii = i
	while ii > 1:
		ii = ii/2 if ii%2 == 0 else 3*ii+1
		counter+=1
	print(counter)
	if counter > maxc:
		maxc = counter
		maxi = i


print(maxi)
