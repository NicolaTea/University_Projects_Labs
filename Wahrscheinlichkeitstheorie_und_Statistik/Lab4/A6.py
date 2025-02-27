#Eine Urne enth¨alt 1 Kugel mit der Ziffer 1, 2 Kugeln mit der Ziffer 2, 3 Kugeln mit der Ziffer 3. Aus der
#Urne werden 2 Kugeln ohne Zur¨ucklegen gezogen. S sei die Summe der beiden Kugeln.
#▶Man generiereN (z.B. 500,1000,...) zuf¨alligeWerte f¨ur S und zeichne das Histogramm der relativen H¨aufigkeiten.
#Auf demselben Bild zeichne man auch die Balken f¨ur die theoretischen Wahrscheinlichkeiten.
#▶ Man sch¨atze zus¨atzlich den Erwartungswert E(S) und berechne den theoretischen Erwartungswert von S.

import random
from itertools import combinations

import numpy
import numpy as np
from matplotlib.pyplot import bar, show, grid, legend, xticks
urne=[1,2,2,3,3,3]
N=1000
sume=[]
for _ in range(N):
    kugelnSample=random.sample(urne,k=2)
    sume.append(sum(kugelnSample))

#E(x)-Simulationen
e_x=np.mean(sume)

z,count=np.unique(sume,return_counts=True)
print("Summen: ", z)
print("Anzahl der erscheinung: ", count)

total_kombinationen=len(list(combinations(urne,2)))
theoretische_wkt=count/total_kombinationen


bar(z,count/N,width=0.9, color="red", edgecolor="black", label="relative Haufigkeiten")
bar(z,theoretische_wkt,width=0.5, color="blue", edgecolor="black", label="Theoretische Wkt.")
legend(loc="lower center")
xticks(range(2, 8))
grid()
show()

# Erwartungswert E(S) theoretisch
e_s_theoretisch = sum(z * theoretische_wkt)

# Ergebnisse ausgeben
print(f"Erwartungswert E(S) aus Simulationen: {e_x}")
print(f"Theoretischer Erwartungswert E(S): {e_s_theoretisch:.2f}")