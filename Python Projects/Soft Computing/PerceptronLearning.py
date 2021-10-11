import numpy as np

class Perceptron(object):
    def __init__(self, input_size, lr=1, epochs=100):
        self.W = np.zeros(input_size+1)
        self.epochs = epochs #No. of iterations for training
        self.lr = lr #Learning rate
    
    def activation_fn(self, x):
        if x > 0:
            return 1
        elif x == 0:
            return 0
        else:
            return -1
 
    def predict(self, x):
        z = self.W.T.dot(x)
        a = self.activation_fn(z)
        return a
 
    def fit(self, X, d):
        for _ in range(self.epochs):
            for i in range(d.shape[0]):
                x = np.insert(X[i], 0, 1)
                y = self.predict(x)
                e = 0 if d[i] == y else d[i]
                self.W = self.W + self.lr * e * x

if __name__ == '__main__':
    X = np.array([
        [-1, -1],
        [-1, 1],
        [1, -1],
        [1, 1]
    ])
    d = np.array([1, -1, -1, -1])
 
    perceptron = Perceptron(input_size=2, epochs=10)
    perceptron.fit(X, d)
    print(f"Weights after {perceptron.epochs} epochs:\n{perceptron.W}\n") #Prints the weights calculated
    test = [1, -1, -1]
    print(f"Prediction for {test[1:]}: {perceptron.predict(test)}") #[bias, x1, x2] Keeping bias always as 1 as bias is always added