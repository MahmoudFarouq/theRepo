def search(lstOfWords):
	lstOfPossibleSolutions = [ [[lstOfWords[i]],[ j for j in range(len(lstOfWords)) if j != i ] ] for i in range(len(lstOfWords))]
	print(lstOfPossibleSolutions)
	while len(lstOfPossibleSolutions) > 0:
		candidate = lstOfPossibleSolutions.pop(0)
		if len(candidate[0]) == 8:
			if doesntViolate(candidate[0]): # here we have all the 8 words, hence this is a goal test
				return candidate[0]
		else:
			for num in candidate[1]:
				newCandidate = [ list(candidate[0]), list(candidate[1]) ]
				newCandidate[0].append(lstOfWords[num])
				del newCandidate[1][ newCandidate[1].index(num) ]
				if doesntViolate(newCandidate[0]):
					lstOfPossibleSolutions.append( newCandidate )
	return False

def doesntViolate(lstOfWords):
	#loop on H's
	for h in range(0, len(lstOfWords), 2):
		#loop on V's
		for v in range(1, len(lstOfWords), 2):
			if lstOfWords[h][v] != lstOfWords[v][h+1]:
				return False
	return True


lstOfWords = ["zombifies", "akecabele", "brickwork", "backcheck", "acmrremad", "nhgwpfabz", "jellybean", "earreoded"]
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


#def doesntViolate(lstOfWords):


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
