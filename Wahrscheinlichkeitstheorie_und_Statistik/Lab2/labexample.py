#Geometrische Wahrscheinlichkeit
import numpy
from matplotlib.pyplot import axis,plot,figure,show,legend
fig=figure()
axis("square")
axis((0,1,0,1))
X=numpy.random.random(25)
Y=numpy.random.random(25)
plot(X,Y,"bo")
#b->blue
#o->buline
fig.suptitle("Beispiel 1 ",fontweight="bold")
show()
fig=figure()
axis("square")
axis((0,1,0,1))
plot(X,numpy.square(X),"g*") # zufallige Punkte auf dem Bild der Funktion f(x)=xˆ2
plot(X[-1],numpy.square(X[-1]),"g*",label="$f(x)=x^2$") #Beispiel fur label
legend(loc="upper left")
fig.suptitle("Beispiel 2",fontweight="bold")
show()
