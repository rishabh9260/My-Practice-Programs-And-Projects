# Data Preprocessing Template

# Importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Importing the dataset
dataset = pd.read_csv('Data.csv')
X = dataset.iloc[:, :-1].values
y = dataset.iloc[:, -1].values

#Taking care of missing data
from sklearn.impute import SimpleImputer
missingValues = SimpleImputer(missing_values = np.nan,strategy = 'mean', verbose = 0)
missingValues = missingValues.fit(X[:, 1:3])
X[:, 1:3] = missingValues.transform(X[:, 1:3])

# Encoding categorical data
# Encoding the independent variable
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
ct = ColumnTransformer([('encoder',OneHotEncoder(),[0])],remainder = 'passthrough')
X = np.array(ct.fit_transform(X), dtype=np.float)
# Encoding the dependent variable
from sklearn.preprocessing import LabelEncoder
y = LabelEncoder().fit_transform(y)