import matplotlib.pyplot as plt
import numpy as np

start = 100
y = []

for i in range(100):
	while start != 1:
		y.append(start)
		if start % 2 == 0:
			start /= 2
		else:
			start = 3*start + 1
	x = np.arange(1, len(y) + 1)
	plt.plot(x, y)
plt.show()

