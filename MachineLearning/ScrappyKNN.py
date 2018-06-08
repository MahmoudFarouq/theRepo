from scipy.spatial import distance
#get distance between two points
def euc(a, b):
    return distance.euclidean(a, b)

#we are hard coding k to be one
class ScrappyKNN(object):
    """docstring for ScrappyKNN."""

    def fit(self, X_train, y_train):
        self.X_train = X_train
        self.y_train = y_train

    def predict(self, X_test):
        predictions = []
        for test in X_test:
            label = self.closest(test)
            predictions.append(label)
        return predictions

    def closest(self, row):
        best_index = 0
        best_distance = euc(row, self.X_train[best_index])
        for i in range(1, len(self.X_train)):
            _ = euc(row, self.X_train[i])
            if _ < best_distance:
                best_distance = _
                best_index = i
        return self.y_train[best_index]



#load data
from sklearn import datasets
iris = datasets.load_iris()

#split into features(x) , labels(y)
X = iris.data
y = iris.target

#build test model
from sklearn.cross_validation import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.5)

#create classifier

"""we are going to create this"""
#from sklearn.neighbors import KNeighborsClassifier
#clf = KNeighborsClassifier()

"""to this"""
clf = ScrappyKNN()

#train the classifier
clf.fit(X_train, y_train)

#predict the X_test
pred = clf.predict(X_test)

#calculate accuracy
from sklearn.metrics import accuracy_score
accuracy = accuracy_score(pred, y_test)

print(accuracy)
