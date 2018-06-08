class PolyRegression:

	def h(self, row):
		predicted = 0
		for i in range(len(row)):
			predicted += row[i]*self.thetas[i]
		return predicted

	def fit(self, train_X, train_y, alpha=0.1, maxIter=10000):

		f = len(train_X[0])

		for i in range(len(train_X)):
			train_X[i].insert(0, 1)

		self.thetas = [ 0 for _ in range(f+1) ]
		self.m = len(train_X)

		#GradiantDescent
		temp_thetas = self.thetas.copy()
		while --maxIter:

			for j in range(len(temp_thetas)):
				temp_val = alpha*(1.0/self.m)*sum( [ (self.h(train_X[i]) - train_y[i])*train_X[i][j] for i in range(len(train_X)) ] )
				temp_thetas[j] = temp_thetas[j] - temp_val

			#square error
			r = (1/(2*self.m))*sum( [ (self.h(train_X[i]) - train_y[i])**2 for i in range(len(train_X)) ] )
			#print(r)

			if(temp_val > 0 and temp_val < 0.0001 or temp_val < 0 and temp_val > -0.0001):
				break

			self.thetas = temp_thetas.copy()

			#print(temp_val)

	def predict(self, test_X):
		for i in range(len(test_X)):
			test_X[i].insert(0, 1)
		return [ self.h(i) for i in test_X ]



f, n =  map(int, input().split(' '))

train_X = []
train_y = []

for j in range(n):
	temp = [ float(_) for _ in input().split(' ')]
	train_X.append(temp[:-1])
	train_y.append( temp[-1] )



t = int(input())
test = []
for j in range(t):
	temp = [ float(_) for _ in input().split(' ')]
	test.append(temp)


clf = PolyRegression()


clf.fit(train_X, train_y)

preds = clf.predict( test )


for i in preds:
	print(i)
