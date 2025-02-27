from scipy.stats import binom
from matplotlib.pyplot import bar, show, grid, legend, xticks
import numpy
N=1000;n=8; p=0.5 #zufallige Werte fur X~Bino(8,0.5)
R = binom.rvs(n, p,size= N)
X,count=numpy.unique(R,return_counts=True)
bar(X,count/N,width=0.9,color="red",edgecolor="black",label="relative Haufigkeiten")
P=[binom.pmf(k,n,p) for k in range(0,n+1)] #theoretische Wkt. fur X~Bino(8,0.5)
bar(X,P,width=0.6,color="yellow",edgecolor="black",label="theoretische Wkt.")
xticks(range(0,n+1))
legend(loc="lower center")
show()
k=0
w=binom.pmf(k,n,p)
print("binom.pmf(",k,",",n,",",p,f") berechnet die theoretische Wkt. P( X ={k:1.0f})={w:.5f}")
