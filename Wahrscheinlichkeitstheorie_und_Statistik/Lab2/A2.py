import math
import numpy
from matplotlib.pyplot import axis,plot,figure,show,legend
#2) Man mochte die Wahrscheinlichkeit schatzen, dass ein zufallig
#gewahlter Punkt im Quadrat [0, 1] × [0, 1] sich auch in dem
#eingeschriebenen Kreis befindet (siehe Bild).
#(2a) Man simuliere N zufallige Punkte im Quadrat und man zahle wie viele im Kreisinneren sind; sei k diese Zahl.
#Man zeichne auf demselben Bild die zufalligen Punkte mit verschiedenen Farben: diejenigen die im bzw. die
#außhalb des Kreisinneren sind. Hinweis: fur die euklidische Distanz zwischen zwei Punkten P1(x1, y1), P2(x2, y2)
#kann man math.dist benutzen oder die Formel dist(P1, P2)
#(2b) Welche ist die theoretische Wahrscheinlichkeit, dass der Punkt im Kreisinneren ist?
#(2c) Anhand von (2a) und (2b) gebe man verschiedene Approximationen von π an.
fig=figure()
axis("square")
axis((0,1,0,1))
N=1000
c=0
X=numpy.random.random(N)
Y=numpy.random.random(N)
for i in range(N):
    if ((X[i] - 0.5) ** 2 + (Y[i] - 0.5) ** 2 <= (0.5) ** 2):
        plot(X[i], Y[i], "m*")
        c = c + 1
    else:
        plot(X[i], Y[i], "y*")
print("Wkt im Kreisinneren aus Simulationen: ",c/N)
print("theoretische Wkt im Kreisinneren: ",math.pi/4) #Radius kreis is 1/2;fl kreis pi*r^2
print("Approximation von PI: ",4*c/N)
show()