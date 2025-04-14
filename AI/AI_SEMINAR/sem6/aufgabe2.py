import pandas as pd
import numpy as np
from sklearn.model_selection import cross_val_score
from sklearn.tree import DecisionTreeClassifier
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis, QuadraticDiscriminantAnalysis
from sklearn.svm import SVC
from sklearn.neural_network import MLPClassifier

dat=pd.read_csv("pima-indians-diabetes.csv",header=None)
X=dat.iloc[:,:-1]
y=dat.iloc[:,-1]

classifiers={
    "Decision Tree":DecisionTreeClassifier(),
    "LDA":LinearDiscriminantAnalysis(),
    "QDA":QuadraticDiscriminantAnalysis(),
    "SVM":SVC(),
    "Neural Network":MLPClassifier(max_iter=1000) #retea neuronala simpla
}


results={}
for name,clf in classifiers.items():
    scores=cross_val_score(clf,X,y,cv=10)
    results[name]=np.mean(scores)

for name,accuracy in results.items():
    print(f"{name}: {accuracy:.2f}")