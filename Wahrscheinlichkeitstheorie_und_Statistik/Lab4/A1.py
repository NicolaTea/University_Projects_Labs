import numpy
from matplotlib.pyplot import bar, show, grid, legend, xticks
N=1000
x=[0,1,3,5]
P=[0.4,0.1,0.3,0.2]
rng = numpy.random.default_rng()
r=rng.choice(x, size=N , replace=True, p=P)
#print(r)
X,count=numpy.unique(r,return_counts=True)
bar(X,count/N,width=0.8,color="red",edgecolor="green",label="relative Haufigkeiten")
bar(x, P, width=0.5, color="blue", edgecolor="black", label="theoretische Wkt.")
legend(loc="upper center")
xticks(range(0, 6))
grid()
show()
