from scipy.stats import norm
import numpy as np
import matplotlib.pyplot as plt
mu=199
sigma=3
N=1000
daten=norm.rvs(mu,sigma,N)
print("Im Mittel sind in einem Beutel: ",np.mean(daten),"g Tee")
print("die Wkt, dass im Beutel weniger als 195g Tee sind, ist schaetzungsweise ",np.mean(daten<195))
print("die theoretische Wkt, dass im Beutel weniger als 195g Tee sind,ist ",norm.cdf(195,mu,sigma))
print("die Wkt.,dass im Beutel zwischen 195g und  198g sind,ist ",np.mean((daten>=195)&(daten<=198)))
print("die theoretische Wkt., dass im Beutel zwischen 195g und 198g sind, ist  ",norm.cdf(198,mu,sigma)-norm.cdf(195,mu,sigma))
print("die Wkt. dass im Beutel mehr als 195g sind, ist ",np.mean(daten>195))
print("die theoretische Wkt. dass in Beutel mehr als 195g sind, ist ",1-norm.cdf(195,mu,sigma))

Anzahl_bins=16
plt.hist(daten,bins=Anzahl_bins,density=True,edgecolor='black',label='rel. Hfg')
x=np.linspace(min(daten),max(daten),100)
plt.plot(x,norm.pdf(x,mu,sigma),label='Dichtefunktion')
plt.legend(loc='upper left')
plt.show()
Hfg,Klasse=np.histogram(daten,bins=Anzahl_bins)
for i in range(Anzahl_bins):
    print(f"{i+1:2d} absolute Hfg. {Hfg[i]:3d} der Klasse [{Klasse[i]:8.4f},{Klasse[i+1]:8.4f}]")

