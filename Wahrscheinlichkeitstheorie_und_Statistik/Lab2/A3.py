import math
import numpy
from matplotlib.pyplot import axis,plot,figure,show,legend
#3) Im Inneren eines Quadrates mit Seitenlange 1 wahlt man zufallig einen Punkt A. Man verbindet A mit den
#Spitzen des Quadrates und man erhalt vier Dreiecke mit gemeinsamer Spitze in A. Anhand von Simulationen
#beantworte man folgende Fragen:
#(1) Welche ist die Wahrscheinlichkeit, dass genau ein Winkel in A stumpf ist?
#(2) Welche ist die Wahrscheinlichkeit, dass genau zwei Winkel in A stumpf sind?
#Man zeichne auf demselben Bild die zuf¨alligen Punkte (entsprechend den F¨allen (1), (2)) mit verschiedenen Farben.
#Stumpfer Winkel ist ein Winkel dessen Maß großer als 90◦ ist.
#Spitzer Winkel ist ein Winkel dessen Maß kleiner als 90◦ ist.
fig=figure()
axis("square")
axis((0,1,0,1))
N=1000
c1=0
c2=0
X=numpy.random.random(N)
Y=numpy.random.random(N)
for i in range(N):
    b1=(X[i]-0.5)**2+(Y[i]-0)**2<=(0.5)**2
    b2=(X[i]-1)**2+(Y[i]-0.5)**2<=(0.5)**2
    b3=(X[i]-0.5)**2+(Y[i]-1)**2<=(0.5)**2
    b4=(X[i]-0)**2+(Y[i]-0.5)**2<=(0.5)**2
    S=int(b1)+int(b2)+int(b3)+int(b4)
    if(S==2):
        plot(X[i],Y[i],"m*") #punkt in einem bluetenblatt
        c1=c1+1
    else:
        plot(X[i],Y[i],"y*") #punkt nicht in einem bluetenblatt
        c2=c2+1
print("Wkt 2. stumpfe Winkeln  aus Simulationen: ",c1/N)
print("Wkt 1. stumpfe Winkeln  aus Simulationen: ",c2/N)

show()
