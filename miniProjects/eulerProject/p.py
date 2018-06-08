
def getSequenceCount(x):
	count = 1
	while(True):
		if(x == 1):
			return count
		if(x % 2 == 0):
			x = x/2
		else:
			x = x*3 +1
		count += 1

counter = 0;

start = 1000000

for i in range(start):
	secCount = getSequenceCount(i)
	if(secCount > counter):
		counter = secCount

print( counter )
	
