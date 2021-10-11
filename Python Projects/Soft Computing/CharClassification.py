import numpy as np

class Perceptron(object):
    def __init__(self, input_size, lr=0.2, epochs=100):
        self.W = np.zeros(input_size+1)
        self.epochs = epochs #No. of iterations for training
        self.lr = lr #Learning rate
    
    def activation_fn(self, x):
        return 1 if x >= 0 else -1
 
    def predict(self, x):
        f = lambda k: "C" if k==1 else "O"
        z = self.W.T.dot(np.insert(x.ravel(), 0, 1))
        a = self.activation_fn(z)
        return f(a)
 
    def fit(self, X, d):
        for _ in range(self.epochs):
            for i in range(d.shape[0]):
                x = np.insert(X[i].ravel(), 0, 1)
                y = d[i]
                self.W = self.W + self.lr * y * x

if __name__ == '__main__':
    X = np.array([
        [[1, 1, 1],
         [1, -1, -1],
         [1, 1, 1]],
        [[1, 1, 1],
         [1, -1, 1],
         [1, 1, 1]]
    ])
    d = np.array([1, -1])
 
    perceptron = Perceptron(input_size=9)
    perceptron.fit(X, d)
    print(perceptron.W) #Prints the weights calculated
    test_data = np.array([[1, 1, -1],
         [1, -1, -1],
         [1, 1, 1]])
    print("The class it belongs to is:", end=" ")
    print(perceptron.predict(test_data))