import matplotlib.pyplot as plt
import random 
import numpy as np
random.seed(21)

def batch_gradient_descent():

	X = [2,3,4,5,6,7,8,9]
	w = 1
	y = [x*6 for x in X]
	costs = []
	_s = []
	alpha = 0.01

	for _ in range(20):
		cost = 0
		for i in range(len(X)):
			cost += (X[i]*w - y[i])**2
		cost /= len(X)

		y_ = [w*x for x in X]

		sum_derivative = 0
		for i in range(len(X)):
			sum_derivative += (y_[i] - y[i])*X[i]

		w = w - alpha*(1/8)*sum_derivative
		print("w = ", w, ", c = ", cost)
		_s.append(_)
		costs.append(cost)

	plt.plot(_s, costs)
	plt.show()

def batch_gradient_descent_multi():

	X = [[i] for i in range(20)]
	y = [ (i[0]*3) for i in X ]
	X = np.array(X)
	w = np.array([1])
	y = np.array(y)

	costs = []
	_s = []
	alpha = 0.01
	m, n = X.shape
	for _ in range(20):

		hx = w.T.dot(X.T)
		cost = (1/m) * (hx - y)**2
		cost = sum(cost)

		w_ = w.copy()
		for j in range(n):
			sum_derivative = (hx - y)*X[:,j]
			sum_derivative = sum(sum_derivative)
			w_[j] = w[j] - alpha*(1/m)*sum_derivative
		w = w_
		print("w = ", w, ", c = ", cost)
		_s.append(_)
		costs.append(cost)

	plt.plot(_s, costs)
	plt.show()


def batch_gradient_descent_multi_vectorized():

	X = np.array([[i] for i in range(20)])
	y = np.array([(i[0]*3) for i in X])
	w = np.array([1])

	costs = []
	_s = []
	alpha = 0.01
	m, n = X.shape
	for _ in range(20):

		hx = w.T.dot(X.T)
		cost = (1/m) * (hx - y)**2
		cost = sum(cost)

		w = w - alpha*(1/m)*(hx - y).dot(X)
		
		print("w = ", w, ", c = ", cost)
		_s.append(_)
		costs.append(cost)

	plt.plot(_s, costs)
	plt.show()



def stochastic_gradient_descent():

	X = [2,3,4,5,6,7,8,9]
	w = 1
	y = [x*6 for x in X]
	costs = []
	_s = []
	alpha = 0.01

	for _ in range(20):
		cost = 0
		for i in range(len(X)):
			cost += (X[i]*w - y[i])**2
		cost /= len(X)

		y_ = [w*x for x in X]

		sum_derivative = 0
		i = random.randint(0, len(X)-1)
		sum_derivative += (y_[i] - y[i])*X[i]
		w = w - alpha*sum_derivative

		print("w = ", w, ", c = ", cost)
		_s.append(_)
		costs.append(cost)

	plt.plot(_s, costs)
	plt.show()

'''
from perceptron import *
stochastic_gradient_descent():
'''
batch_gradient_descent_multi()
