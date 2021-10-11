import numpy as np
from numpy.linalg import norm
from sklearn.datasets import make_blobs
from matplotlib import pyplot as plt
from sklearn.preprocessing import StandardScaler

class Kmeans:
    '''Implementing Kmeans algorithm.'''

    def __init__(self, n_clusters, max_iter=1000, random_state=1):
        self.n_clusters = n_clusters
        self.max_iter = max_iter
        self.random_state = random_state

    def initializ_centroids(self, X):
        np.random.RandomState(self.random_state)
        random_idx = np.random.permutation(X.shape[0])
        centroids = X[random_idx[:self.n_clusters]]
        return centroids

    def compute_centroids(self, X, labels):
        centroids = np.zeros((self.n_clusters, X.shape[1]))
        for k in range(self.n_clusters):
            centroids[k, :] = np.mean(X[labels == k, :], axis=0)
        return centroids

    def compute_distance(self, X, centroids):
        distance = np.zeros((X.shape[0], self.n_clusters))
        for k in range(self.n_clusters):
            row_norm = norm(X - centroids[k, :], axis=1)
            distance[:, k] = np.square(row_norm)
        return distance

    def find_closest_cluster(self, distance):
        return np.argmin(distance, axis=1)

    def compute_sse(self, X, labels, centroids):
        distance = np.zeros(X.shape[0])
        for k in range(self.n_clusters):
            distance[labels == k] = norm(X[labels == k] - centroids[k], axis=1)
        return np.sum(np.square(distance))
    
    def fit(self, X):
        self.centroids = self.initializ_centroids(X)
        for i in range(self.max_iter):
            old_centroids = self.centroids
            distance = self.compute_distance(X, old_centroids)
            self.labels = self.find_closest_cluster(distance)
            self.centroids = self.compute_centroids(X, self.labels)
            if np.all(old_centroids == self.centroids):
                break
        self.error = self.compute_sse(X, self.labels, self.centroids)
    
    def predict(self, X):
        distance = self.compute_distance(X, self.centroids)
        return self.find_closest_cluster(distance)

def main():
    # Creating a cluster dataset
    X, y = make_blobs(n_samples=100, centers=3, random_state=43)

    plt.scatter(X[:, 0], X[:, 1])
    plt.xlabel('Feature 1')
    plt.ylabel('Feature 2')
    plt.title('Visualization of raw data')
    plt.show()

    # Standardize the data
    # X_std = StandardScaler().fit_transform(X)
    X_std = X
    
    # Run local implementation of kmeans
    km = Kmeans(n_clusters=3)
    km.fit(X_std)
    centroids = km.centroids
    y_pred = km.labels
    
    # Plot the clustered data
    fig, ax = plt.subplots(figsize=(6, 6))
    scatter = ax.scatter(X_std[:, 0], X_std[:, 1], c=y_pred, alpha=0.95)
    handles, labels = scatter.legend_elements(alpha=0.95, fmt="Cluster {x:.0f}", func=lambda x: x+1)
    handles.append(plt.scatter(centroids[:, 0],centroids[:, 1],s=100, c='red', alpha=1, marker='*'))
    labels.append("Centroid")
    print(handles, labels)
    legend1 = ax.legend(handles=handles, labels=labels)
    ax.add_artist(legend1)
    # plt.xlim(-2, 2)
    # plt.ylim(-2, 2)
    plt.xlabel('Feature 1')
    plt.ylabel('Feature 2')
    plt.title('Visualization of clustered data', fontweight='bold')
    plt.show()

if __name__ == '__main__':
    main()