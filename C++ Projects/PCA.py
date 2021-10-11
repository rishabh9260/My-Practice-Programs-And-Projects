import numpy as np
from sklearn import datasets
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split

def pca_np(x):
    #centering data
    m = np.mean(x, axis =0)
    x_centered = x - m

    #calculating covariance matrix
    x_cov = np.cov(x_centered.T)

    #eigendecomposition
    eigenvals, eigenvecs = np.linalg.eig(x_cov)

    #sorting
    i = np.argsort(eigenvals)[::-1]
    eigenvecs = eigenvecs[:,i]
    eigenvals = eigenvals[i]

    #returning the eigenvalues, eigenvectors and means
    return(eigenvals, eigenvecs, m)

def main():
    #importing the data
    iris = datasets.load_iris()
    X = iris.data
    y = iris.target

    iris_evals, iris_evecs, iris_mean = pca_np(X)

    print("Eigen Values:", iris_evals)
    print("Eigen Vectors:\n", iris_evecs)

    exp_var =iris_evals/sum(iris_evals)
    print("\nPercentages of Variance:", exp_var)

    # Plot % of variance explained
    plt.bar(range(1,5),exp_var)
    plt.show()

    # Number of components to keep
    n = 2

    # Train test split 80/20
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.20, random_state=123)

    # Applying our PCA function
    X_evals, X_evecs, X_mean = pca_np(X_train)

    # Retaining the eigenvectors for first 2 PCs
    X_evecs_n = X_evecs[:,:n]

    # Projecting the training and test data back onto the retained #eigenvectors to get our factors for use in predictive algorithms
    X_factors_train = np.dot(X_train-X_mean,X_evecs_n)
    X_factors_test= np.dot(X_test-X_mean,X_evecs_n)

    # Checking the dimensions before and after PCA
    print("\nTraining Set Dimensions:", X_train.shape)
    print("Test Set Dimensions:", X_test.shape)
    print("Training Set Dimensions after PCA:", X_factors_train.shape)
    print("Test Set Dimensions after PCA:", X_factors_test.shape)

if __name__ == "__main__":
    main()