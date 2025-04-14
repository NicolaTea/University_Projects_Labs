#În loc să împărțim datele o singură dată în antrenare/test, cross-validation împarte datele în n bucăți
# și antrenează modelul de n ori, folosind de fiecare dată o altă bucată pentru testare.
#✅ Avantaj: Acuratețea modelului nu depinde de o singură împărțire a datelor.

import pandas as pd
import numpy as np
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import cross_val_score

dat=pd.read_csv("pima-indians-diabetes.csv",header=None)

X=dat.iloc[:,:-1] # toate coloanele,mai putin ultima
y=dat.iloc[:,-1] #ultima coloana
# 0=fara diabet / 1=cu diabet

def cv(clf,features,classes,n):
    scores=cross_val_score(clf,features,classes,cv=n) #n-fold CV
    return np.mean(scores)

clf=DecisionTreeClassifier()

accuracy=cv(clf,X,y,10)
print(f"Acuratețea medie: {accuracy:.2f}")