import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

from sklearn.preprocessing import LabelBinarizer
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score

X = np.array([
		[10.0, 6],
		[20.0, 5],
		[5.0 , 4],
		[2.0 , 5],
		[2.0 , 5],
		[3.0 , 6],
		[10.0, 7],
		[15.0, 8],
		[5.0 , 9]
	])

Y = ['Lorry', 'Lorry', 'Van', 'Van', 'Van', 'Lorry', 'Lorry', 'Lorry', 'Lorry']

lb = LabelBinarizer()
Y_bin = lb.fit_transform(Y)

clf = MLPClassifier(solver='lbfgs', alpha=1e-5, hidden_layer_sizes=(5, 2), random_state=1)
clf.fit(X, Y_bin)

pred = clf.predict(X)
pred_Labels = lb.inverse_transform(pred)

print("the accuracy is: "+ str(accuracy_score(Y_bin, pred)) )
print("the predicted labels are: ")
print(pred_Labels)


df = pd.DataFrame(data=X, columns=['Mass', 'Length'])
df['Class'] = Y
groups = df.groupby('Class')
fig, ax = plt.subplots()
ax.margins(0.05)
for name, group in groups:
    ax.plot(group.Mass, group.Length, marker='o', linestyle='', ms=12, label=name)

ax.legend()
plt.show()