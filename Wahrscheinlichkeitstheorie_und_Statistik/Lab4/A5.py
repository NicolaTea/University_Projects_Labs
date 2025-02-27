#Ein Zufallsgenerator generiert Zufallszahlen f¨ur die Verteilung Unid(3), d.h.
#Sei X die Anzahl der generierten Zahlen, bevor die erste 3 auftaucht.
#▶ Man generiere N (z.B. 1000) zuf¨allige Werte f¨ur X und zeichne das Histogramm
# der relativen H¨aufigkeiten.
#▶ Man sch¨atze zus¨atzlich P(X ≤ 2), P(X > 2) und den Erwartungswert E(X).

import numpy
from matplotlib.pyplot import bar, show, grid, legend, xticks
n = 1000
x = [1,2,3]
P = [1/3, 1/3, 1/3]
X = []

rng = numpy.random.default_rng()
U = rng.choice(x,size = 1, replace = True, p = P)
cnt = 0
for i in range(n):
    cnt = 0
    U = rng.choice(x, size=1, replace=True, p=P)
    while U != 3:
        U = rng.choice(x, size=1, replace=True, p=P)
        cnt += 1
    X.append(cnt)

print(X)

# rng = numpy.random.default_rng()
# r = rng.choice(x, size=n , replace=True, p=P)
XX, count = numpy.unique(X,return_counts= True)
bar(XX,count/n, width = 0.8, color = 'red', edgecolor = "green", label = "rellative Haufigkeiten")
legend(loc = "upper center")
xticks(range(0,max(XX) + 1))
grid()
show()