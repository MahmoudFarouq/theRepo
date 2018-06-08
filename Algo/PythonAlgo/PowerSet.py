"""
	THE IDEA IS:
		suppose you have list = [1,2,3]
		then, the number of all the possible solutions is 2**len(list)
			it's because: it's either you take the item with you or not:
				which let us see the cobinations as array of binary elements: 0 if we didnt take it, 1 o.w
				example{
					[0,0,0] => []
					[0,0,1] => [3]
					[0,1,0] => [2]
					[0,1,1] => [2, 3]
					[1,0,0] => [1]
					[1,0,1] => [1, 3]
					[1,1,0] => [1, 2]
					[1,1,1] => [1, 2, 3]
				}
		so we need to consider this binary array which value ranges between {0 --> 2**n-1}
		so every i{i'th binary array} equals the value of the array
		so if i = 5 the array = [1, 0, 1]
		ok, now we need to go over every i:
			go over every bit in i:	{ you can do this by left shifting the i j times ( i >> j)}
				if this bit == 1: 	{ take the modulo of ( i >> j) % 2 }
					put the bit'th item in a temp array
			put the temp array in the combos array
"""


# generate all combinations of N items
def powerSet(items):
    N = len(items)
    # enumerate the 2**N possible combinations
    for i in range(2**N):
        combo = []
        for j in range(N):
            # test bit jth of integer i
            if (i >> j) % 2 == 1:
                combo.append(items[j])
        yield combo

def myPowerSet(items):
	n = len(items)
	allCombinations = []
	for i in range(2**n): # 2**n is the number of all combinations we can do from n items list
		cobination = []
		for j in range(n):
			if ( (i >> j) % 2 == 0 ):
				cobination.append( items[j] )
		allCombinations.append(cobination)
	return allCombinations


gen = powerSet([1,2,3])
for i in range( 2**3 ):
	print(next(gen))

gen = myPowerSet([1,2,3])
print(gen)
