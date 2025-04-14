import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn import tree

df=pd.read_csv("iris.csv")

X=df.iloc[:,1:5]
y=df.iloc[:,5]

X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.33)

clf=tree.DecisionTreeClassifier()
clf=clf.fit(X_train,y_train)

pred=clf.predict(X_test)
print(np.mean(pred==y_test))


#train -> date pt antrenare(modelul invatat din ele)
#test -> date pt testare (verificam daca modelul a invatat bine)
# test_size=0.33 -> 33% testare, 67% antrenare