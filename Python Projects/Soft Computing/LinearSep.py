import numpy as np
import matplotlib.pyplot as  plt

class Perceptron(object):
    def __init__(self, input_size, lr=1, epochs=100):
        self.W = np.zeros(input_size+1)
        self.epochs = epochs #No. of iterations for training
        self.lr = lr #Learning rate
    
    def activation_fn(self, x):
        return 1 if x >= 0 else -1
 
    def predict(self, x):
        z = self.W.T.dot(x)
        a = self.activation_fn(z)
        return a
 
    def fit(self, X, d):
        for _ in range(self.epochs):
            for i in range(d.shape[0]):
                x = np.insert(X[i], 0, 1)
                y = self.predict(x)
                e = d[i] - y #error calculation
                self.W = self.W + self.lr * e * x

if __name__ == '__main__':
    X = np.array([
        [-1, -1],
        [-1, 1],
        [1, -1],
        [1, 1]
    ])
    d = np.array([-1, -1, -1, 1])
 
    perceptron = Perceptron(input_size=2)
    perceptron.fit(X, d)
    weights = perceptron.W
    print(weights) #Prints the weights calculated

    m = -1 * (weights[1]/weights[2])
    c = -1 * (weights[0]/weights[2])

    fig, ax = plt.subplots()
    ax.set_xlim(-2, 2)
    ax.set_ylim(-2, 2)
    ax.plot(0, "-")
    ax.grid(True, which='both')
    ax.axhline(y=0, color='k')
    ax.axvline(x=0, color='k')
    ax.scatter(-1, -1, c="r")
    ax.scatter(-1, 1, c="r")
    ax.scatter(1, -1, c="r")
    ax.scatter(1, 1, c="g")
    x_vals = np.arange(-3,3, 0.1)
    ax.plot(x_vals, (m * x_vals + c), "-b")
    plt.show()
