import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from scipy.stats import mode
from sklearn.preprocessing import LabelEncoder

# KNN Classifier Class
class KNN_Classifier():

    def __init__(self, K):

        self.K = K

    # Function to store training set

    def fit(self, X_train, Y_train):

        self.X_train = X_train

        self.Y_train = Y_train

        # no_of_training_examples, no_of_features

        self.m, self.n = X_train.shape

    # Function for prediction

    def predict(self, X_test):

        self.X_test = X_test

        # no_of_test_examples, no_of_features

        self.m_test, self.n = X_test.shape

        # initialize Y_predict

        Y_predict = np.zeros(self.m_test)

        for i in range(self.m_test):

            x = self.X_test[i]

            # find the K nearest neighbors from current test example

            neighbors = np.zeros(self.K)

            neighbors = self.find_neighbors(x)

            # most frequent class in K neighbors

            Y_predict[i] = mode(neighbors)[0][0]

        return Y_predict

    # Function to find the K nearest neighbors to current test example

    def find_neighbors(self, x):

        # calculate all the euclidean distances between current
        # test example x and training set X_train

        Hamming_distances = np.zeros(self.m)

        for i in range(self.m):

            d = self.Hamming(x, self.X_train[i])

            Hamming_distances[i] = d

        # sort Y_train according to euclidean_distance_array and
        # store into Y_train_sorted

        inds = Hamming_distances.argsort()

        Y_train_sorted = self.Y_train[inds]

        return Y_train_sorted[:self.K]

    # Function to calculate Hamming distance

    def Hamming(self, x, x_train):
        sum = 0
        for i in range(self.n):
            if x[i] != x_train[i]:
                sum += 1
        return sum

    def score(self, x_test, y_test):

        y_pred = self.predict(x_test)

        correct = 0
        count = 0
        for count in range(np.size(y_pred)):

            if y_test[count] == y_pred[count]:

                correct = correct + 1

            count = count + 1
        return correct/count

# Main function (Driver Code)
def main():
    #Loading the Dataset and Preprocessing
    df = pd.read_csv("E:\VS Code Workspaces\Projects\C++ Projects\Pattern Recognition\BalanceScale.csv")
    X = df.iloc[:, 1:].values
    Y = LabelEncoder().fit_transform(df.iloc[:, 0])
    
    # Displaying some of the data from the dataset
    # print(X.head())
    # print(Y.head())

    # Splitting the dataset into Training Set and Test Set
    training_data, validation_data, training_labels, validation_labels = train_test_split(
        X, Y, test_size=0.2, random_state=0)

    # print(len(training_data),len(training_labels))

    # Testing the Classification against different values of K
    accuracies = []
    for k in range(1, 101):
        classifier = KNN_Classifier(K=k)
        classifier.fit(training_data, training_labels)
        accuracies.append(classifier.score(
            validation_data, validation_labels)*100)

    # Plotting our findings
    k_list = range(1, 101)
    plt.grid(True, which="both")
    plt.xticks(np.arange(0,101,5))
    plt.plot(k_list, accuracies, "b-")
    plt.xlabel("Values of K")
    plt.ylabel("Validation Accuracy (in %)")
    plt.title("Balance Scale Classifier Accuracy")
    plt.show()


if __name__ == "__main__":
    main()
