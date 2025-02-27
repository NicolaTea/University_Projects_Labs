import numpy
from matplotlib.pyplot import axis,plot,figure,show,legend
#4) Man schreibe ein Programm (in Python), in welchem ein Bild mit N = 500 roten zufalligen Punkten generiert
#wird −→ wie im unteren Bild. Man schatze die Wahrscheinlichkeit, dass ein zufallig gewahlter Punkt aus dem
#Quadrat sich im Inneren des unteren oder oberen Dreieckes befindet (wie im Bild).
#Hinweis 1: Um zu uberprufen, ob ein Punkt A(x, y) uber oder unter dem Graphen einer Funktion f liegt: Der
#Punkt A liegt uber dem Graphen von f, wenn y > f(x), bzw. unter dem Graphen von f, wenn y < f(x).
fig=figure()
axis("square")
axis((0,1,0,1))
X=numpy.linspace(0,1,100)
plot(X,X,"k-") #diag1  f(x)=x
plot(X,1-X,"b-") #diag2  f(x)1-x
N=500
c1=0
for i in range(N):
    x=numpy.random.random()
    y=numpy.random.random()
    if((y>x) and y>1-x): #uber den Graph
        plot(x,y,"r.")
        c1=c1+1
    if((y<x) and y<1-x): #unter den Graph
        plot(x,y,"r.")
        c1=c1+1
print("Wkt 2 stumpfe Winkel aus Simulationen: ",c1/N)
plot(x,y,"r.",label="zufalliger Punkte")
legend(loc="center left")
show()