def search(lstOfWords):
	lstOfPossibleSolutions = initializePossibleSolutions(lstOfWords)
	return depth_first_search(lstOfPossibleSolutions)

def depth_first_search(lstOfPossibleSolutions):
	if len(lstOfPossibleSolutions) == 0:
		return False
	candidate = lstOfPossibleSolutions.pop(0)
	if len(candidate[0]) == 8:
			if DoesntViolate(candidate[0]): # here we have all the 8 words, hence this is a goal test
				return candidate[0]
	else:
		getNewPossibleSolutions(lstOfPossibleSolutions, candidate)
		return depth_first_search(lstOfPossibleSolutions)

def getNewPossibleSolutions(lstOfPossibleSolutions, candidate, index = 0):
	if index == len(candidate[1]):
		return
	newCandidate = [ list(candidate[0]), list(candidate[1]) ]
	newCandidate[0].append(lstOfWords[candidate[1][index]])
	del newCandidate[1][ newCandidate[1].index(candidate[1][index]) ]
	if(DoesntViolate(newCandidate[0])):
		lstOfPossibleSolutions.append( newCandidate )
	return getNewPossibleSolutions(lstOfPossibleSolutions, candidate, index+1)

def initializePossibleSolutions(lstOfWords, numbers = [0,1,2,3,4,5,6,7], result = [], index = 0):
	if index == len(lstOfWords):
		return result
	result.append([ [lstOfWords[index]], list(numbers[:index]+numbers[index+1:]) ])
	return initializePossibleSolutions(lstOfWords, numbers, result, index+1)

def DoesntViolate(lstOfWords):
	return outerDoesntViolate(lstOfWords, 0, 1)

def outerDoesntViolate(lstOfWords, h, v):
	if h >= len(lstOfWords):
		return True
	if innerDoesntViolate(lstOfWords, h, v):
		return outerDoesntViolate(lstOfWords, h+2, v+2)
	return False

def innerDoesntViolate(lstOfWords, h, v):
	if v >= len(lstOfWords):
		return True
	if lstOfWords[h][v] != lstOfWords[v][h+1]:
		return False
	return innerDoesntViolate(lstOfWords, h, v+2)


lstOfWords = ["zombifies", "brickwork", "akecabele", "earreoded", "backcheck", "acmrremad", "nhgwpfabz", "jellybean"]
print(search(lstOfWords))




'''

the list of possible solutions contains
the words currently taken AND indeces of words that aren't taken yet in the lstOfWords

[
[['zombifies'], [1, 2, 3, 4, 5, 6, 7]],
[['akecabele'], [0, 2, 3, 4, 5, 6, 7]],
[['brickwork'], [0, 1, 3, 4, 5, 6, 7]],
[['backcheck'], [0, 1, 2, 4, 5, 6, 7]],
[['acmrremad'], [0, 1, 2, 3, 5, 6, 7]],
[['nhgwpfabz'], [0, 1, 2, 3, 4, 6, 7]],
[['jellybean'], [0, 1, 2, 3, 4, 5, 7]],
[['earreoded'], [0, 1, 2, 3, 4, 5, 6]]
]

'''




'''
def Goal(lstOfWords):
	H1, V1, H2, V2, H3, V3, H4, V4 = lstOfWords
	return (H1[1] == V1[1] and H2[1] == V1[3] and H3[1] == V1[5] and H4[1] == V1[7] and
			H1[3] == V2[1] and H2[3] == V2[3] and H3[3] == V2[5] and H4[3] == V2[7] and
			H1[5] == V3[1] and H2[5] == V3[3] and H3[5] == V3[5] and H4[5] == V3[7] and
			H1[7] == V4[1] and H2[7] == V4[3] and H3[7] == V4[5] and H4[7] == V4[7])

def two_word(lstOfWords):
	H1, V1 = lstOfWords
	return H1[1] == V1[1]

def three_word(lstOfWords):
	H1, V1, H2 = lstOfWords
	return 

and so on..
'''



# not solved
'''
lstOfWords = [
	"zombifies",
	"akecabele",
	"brickwork",
	"backcheck",
	"acmrremad",
	"nhgwpfabz",
	"jellybean",
	"earreoded"
]
print(doesntViolate(lstOfWords))
'''


# solved 
'''
lstOfWords = [
	"earreoded",
	"backcheck",
	"akecabele",
	"brickwork",
	"nhgwpfabz",
	"zombifies",
	"acmrremad",
	"jellybean"
]
print(doesntViolate(lstOfWords))
'''


'''
[
[z,o,m,b,i,f,i,e,s], 
[a,k,e,c,a,b,e,l,e], 
[b,r,i,c,k,w,o,r,k], 
[b,a,c,k,c,h,e,c,k],
[a,c,m,r,r,e,m,a,d],
[n,h,g,w,p,f,a,b,z],
[j,e,l,l,y,b,e,a,n],
[a,e,r,r,e,o,d,e,d]
]
'''

'''
[
[e,a,r,r,e,o,d,e,d],
[b,a,c,k,c,h,e,c,k],
[a,k,e,c,a,b,e,l,e], 
[b,r,i,c,k,w,o,r,k], 
[n,h,g,w,p,f,a,b,z],
[z,o,m,b,i,f,i,e,s], 
[a,c,m,r,r,e,m,a,d],
[j,e,l,l,y,b,e,a,n]
]
'''

'''
initializePossibleSolutions([
[z,o,m,b,i,f,i,e,s], 
[a,k,e,c,a,b,e,l,e], 
[b,r,i,c,k,w,o,r,k], 
[b,a,c,k,c,h,e,c,k],
[a,c,m,r,r,e,m,a,d],
[n,h,g,w,p,f,a,b,z],
[j,e,l,l,y,b,e,a,n],
[a,e,r,r,e,o,d,e,d]
], [0,1,2,3,4,5,6,7], 1, Result).

'''