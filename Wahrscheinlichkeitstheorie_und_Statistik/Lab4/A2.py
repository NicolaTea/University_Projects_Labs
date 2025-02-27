#U¨ ber die Zufallsgro¨ße X= Anzahl von Fehlern in den online Artikeln einer bestimmten Zeitung ist bekannt:
#in 25% der Artikeln sind keine Tippfehler, in 35% der Artikel ist ein Tippfehler, in 25% der Artikel sind zwei, in
#10% drei und auf dem Rest vier Tippfehler.
#▶ Man generiere zuf¨allige Werte f¨ur X.
#▶ Man sch¨atze anhand der Simulationen die Wahrscheinlichkeit, dass h¨ochstens 1 Tippfehler in einem zuf¨allig
#gew¨ahlten Artikel auftaucht.
#▶ Wie viele Tippfehler sind durchschnittlich (im Mittel) in einem online Artikel dieser Zeitung zu erwarten, d.h.
#man verlangt die Sch¨atzung von dem Erwartungswert E(X). Man berechne den theoretischen Erwartungswert.
import numpy
from matplotlib.pyplot import bar, show, grid, legend, xticks
N=1000
x=[0,1,2,3,4]
P=[0.25,0.35,0.25,0.1,0.05]
rng = numpy.random.default_rng()
R=rng.choice(x, size=N, replace=True, p=P)
X, count = numpy . unique(R, return_counts=True)
bar(X, count/N, width=0.8, color="red", edgecolor="green", label="relative Haufigkeiten")
bar(x, P, width=0.5, color="blue", edgecolor="black", label="theoretische Wkt.")
legend(loc="lower center")
xticks(range(0,6))
grid()
show()
print("(Aus Simulationen) Hochstens 1 Tippfehler ist: ",count[0]/N+count[1]/N)
print("(Theoretische) Hochstens 1 Tippfehler ist: ",P[0]+P[1])

Erwartungswert=sum([x[i]*P[i] for i in range(len(x))]) #theoretische Erwartungswert
print("Erwartungswert aus Simulationen: ",numpy.mean(R))
print(f"Erwartungswert theoretisch: {Erwartungswert:2.3f}")
