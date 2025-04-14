import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df=pd.read_csv("iris.csv")
#print(df)

# : ->alege toate randurile
accx=df.loc[:,"SepalLength"] #[row,column]
#print(accx)


acc=df.iloc[:,1:4]
#print(acc)

#loc -> selects data using row and columns name(labels)
#iloc -> uses numerical indices(positions)


asc=df.iloc[0:5,:]
#print(asc)

beide=df.loc[0:5,["SepalLength","SepalWidth"]]
#print(beide)

#sa folosim expresii boolean ca sa luam datele
#in cazu asta werte<5 din column SepalLength
expr=df.loc[df.SepalLength<5,:]
#print(expr)

df.loc[df.SepalLength<0,"SepalLength"]
#print(df)

