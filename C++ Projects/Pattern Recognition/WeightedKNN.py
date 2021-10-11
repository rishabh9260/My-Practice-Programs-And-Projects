import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from scipy.stats import mode
from sklearn.preprocessing import LabelEncoder, MinMaxScaler

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

            # find the K nearest neighbors from current test example and calculate weights

            neighbors, distances = np.zeros(self.K), np.zeros(self.K)

            neighbors, distances = self.find_neighbors(x)

            denom = distances[-1] - distances[0]
            freq = {a:0 for a in np.unique(neighbors)}
            for j in range(len(neighbors)):
                if denom == 0:
                    freq[neighbors[j]] += (distances[-1] - distances[j])
                else:
                    freq[neighbors[j]] += (distances[-1] - distances[j])/denom

            # Class according to the highest weighted frequency

            Y_predict[i] = max(freq, key=freq.get)

        return Y_predict

    # Function to find the K nearest neighbors to current test example

    def find_neighbors(self, x):

        # calculate all the euclidean distances between current
        # test example x and training set X_train

        euclidean_distances = np.zeros(self.m)

        for i in range(self.m):

            d = self.euclidean(x, self.X_train[i])

            euclidean_distances[i] = d

        # sort Y_train according to euclidean_distance_array and
        # store into Y_train_sorted

        inds = euclidean_distances.argsort()

        d_sorted = euclidean_distances[inds]
        Y_train_sorted = self.Y_train[inds]


        return Y_train_sorted[:self.K], d_sorted[:self.K]

    # Function to calculate euclidean distance

    def euclidean(self, x, x_train):

        return np.sqrt(np.sum(np.square(x - x_train)))

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
    # Loading the Dataset
    df = pd.read_csv("E:\VS Code Workspaces\Projects\C++ Projects\Pattern Recognition\diagnosis.csv")
    X = df.iloc[:, :-1]
    y = df.iloc[:, -1]

    # print(X.head())
    # print(y.head())

    # Performing Preprocessing
    le = LabelEncoder()
    categorical = X.iloc[:,1:]
    X[["Temperature of patient"]] = MinMaxScaler().fit_transform(X[["Temperature of patient"]])
    categorical = categorical.apply(le.fit_transform)
    y = le.fit_transform(y)
    X = pd.merge(X[["Temperature of patient"]], categorical, left_index=True, right_index=True)
    X = X.values

    # Splitting the dataset into Training Set and Test Set
    training_data, validation_data, training_labels, validation_labels = train_test_split(
        X, y, test_size=0.5, random_state=43)

    # print(len(training_data),len(training_labels))

    # Testing the Classification against different values of K
    accuracies = []
    for k in range(3, 101): # k has to be a minimum of 3 for weighted KNN
        classifier = KNN_Classifier(K=k)
        classifier.fit(training_data, training_labels)
        accuracies.append(classifier.score(
            validation_data, validation_labels)*100)

    # Plotting our findings
    k_list = range(3, 101)
    plt.plot(k_list, accuracies, "b-")
    plt.xlabel("Values of K")
    plt.ylabel("Validation Accuracy (in %)")
    plt.title("Acute Inflammation Classifier Accuracy")
    plt.show()

if __name__ == "__main__":
    main()
