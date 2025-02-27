#In einem Computerpool sind 7 Rechner. DieWahrscheinlichkeit, dass ein neuer Virus
#einen Rechner angreift ist 0.4, unabh¨angig von anderen Rechnern.
#▶ Welche ist die Wahrscheinlichkeit, dass der Virus:
#a) h¨ochstens 3 Rechner;
#b) mindestens 4 Rechner;
#c) genau 4 Rechner angreift?

from scipy.stats import binom
import numpy
N=1000;n=7;p=0.4
R=binom.rvs(n,p,size=N)
X,count=numpy.unique(R,return_counts=True)
P=[binom.pmf(k,n,p) for k in range(0,n+1)]
print("Aus Simulationen: Wkt. hochstens 3 Rechner angegriffen", (1/N)* sum([count[i] for i in range(4)]) )
print("Theoretisch: Wkt. hochstens 3 Rechner angegriffen", binom.cdf(3,n,p)) #P(X <= 3)

print("Aus Simulationen: Wkt. mindestens 4 Rechner angegriffen", (1/N)* sum([count[i] for i in range(4, len(count))]) )
print("Theoretisch: Wkt. mindestens 4 Rechner angegriffen", 1-binom.cdf(4, n, p)+binom.pmf(4, n, p)) #penultima

print("Aus Simulationen: Wkt. genau 4 Rechner angegriffen", count[4]/N)
print("Theoretisch: Wkt. genau 4 Rechner angegriffen", binom.pmf(4, n, p)) #P(X = 4)

