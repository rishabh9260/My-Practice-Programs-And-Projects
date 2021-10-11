import numpy as np

class Perceptron(object):
    def __init__(self, input_size, lr=0.1, epochs=100000, MaxError=1e-30):
        self.W = np.empty(input_size+1)
        self.W.fill(0.1)
        self.epochs = epochs #No. of iterations for training
        self.lr = lr #Learning rate
        self.MaxError = MaxError #Max Permissible
        self.TotalError = 0
    
    def activation_fn(self, x):
        return 1 if x >= 0 else -1
 
    def predict(self, x):
        f = lambda k: "C" if k==1 else "O"
        z = self.W.T.dot(np.insert(x.ravel(), 0, 1))
        a = self.activation_fn(z)
        return f(a)
 
    def fit(self, X, d):
        for e in range(self.epochs):
            epoch_error = 0
            for i in range(d.shape[0]):
                x = np.insert(X[i].ravel(), 0, 1)
                z = self.W.T.dot(x)
                r = d[i] - z
                self.W = self.W + self.lr * r * x
                epoch_error += np.square(r)
            self.TotalError += epoch_error
            if epoch_error <= self.MaxError:
                print(f"Training stopped at Epoch {e} as epoch error is less than {self.MaxError}")
                break

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