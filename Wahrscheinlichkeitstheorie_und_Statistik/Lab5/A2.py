import numpy
from matplotlib import pyplot as plt
from scipy.stats import expon, norm

L=1/12 # X ~Exp(1/12) L = lambda
N=1000
Daten = expon.rvs(loc=0,scale=1/L,size=N)
# print(Daten)

# a
print("Druckzeit fur das Drucken eines Plakats", numpy.mean(Daten))
print("Theoretische Wkt fur das Drucken eines Plakats", 1/L, "Sekunden")

# b
plt.hist(Daten,bins=15,density=True,edgecolor="black",label="rel.Hfg.")

x = numpy.linspace(min(Daten), max(Daten), 100)
y = expon.pdf(x, 0, 1/L)
plt.plot(x, y, "g-")
plt.legend()
plt.show()

# c
print("P(T<20)", numpy.mean(Daten < 20))
print("P(T>10)",numpy.mean(Daten > 10))
print("P(10<T<30)", numpy.mean((Daten > 10) & (Daten < 30)))

print("Theoretische Wkt (T<20)", norm.cdf(20, 0, 1/L))
print("Theoretische Wkt (T>10)", 1 - norm.cdf(10, 0, 1/L))
print("Theoretische Wkt (10<T<30)", norm.cdf(30, 0, 1/L) - norm.cdf(10,0,1/L))