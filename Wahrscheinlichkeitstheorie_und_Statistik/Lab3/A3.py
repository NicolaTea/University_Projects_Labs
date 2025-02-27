#Drei W¨urfel werden geworfen. Das Spiel gewinnt derjenige, der die Summe der drei aufgetauchten
#Zahlen vorhersagt.
#(1)Man simuliere dieses Spiel N-mal (z.B. 1000), man erstelle das Histogramm der relativen H¨aufigkeiten.
#Auf demselben Bild zeichne man auch die Balken f¨ur die theoretischen Wahrscheinlichkeiten. Man
#vergleiche die theoretischen Ergebnisse mit den erhaltenen Werten aus den Simulationen.
#(2) Auf welche Zahl (oder Zahlen) muss man wetten, um die gr¨oßten Gewinnchancen zu haben?
#(3) Welche ist die theoretische Wahrscheinlichkeit, dass diese Zahl (oder Zahlen) auftaucht? Man
#vergleiche das theoretische Resultat mit den erhaltenen Ergebnissen der Simulationen.
import numpy
from random import randrange
from matplotlib.pyplot import bar, show,hist, grid, legend, xticks
N=1000
daten=[randrange(1,7)+randrange(1,7) for _ in range(N)]
#print(daten)
z,count=numpy.unique(daten,return_counts=True)
#print(z,count)
bar(z,count/N,width=0.9,color="red",edgecolor="black",label="relative Haufigkeiten")
s=[]
for i in range(1,7):
    for j in range(1,7):
        for k in range(1,7):
            s.append(i+j+k)
zs,counts=numpy.unique(s,return_counts=True)
bar(zs,counts/len(s),width=0.6,color="yellow",edgecolor="black",label="theoretische Wkt.")
ms=max(count)
for i in range(len(z)):
    if count[i]==ms:
        print("(Aus Simulationen) Man wette auf die Summe:", z[i], "diese hat die relative Haufigkeit", count[i] / N)
M=max(counts)
for i in range(len(zs)):
    if counts[i]==M:
        print("(Theoretisch) Man wette auf die Summe:", zs[i], "diese hat die theoretische Wkt.", counts[i] / len(s))
legend(loc="lower center")
xticks(range(3, 19))
grid()
show()
