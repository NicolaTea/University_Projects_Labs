from scipy.stats import uniform,expon
import numpy as np
import matplotlib.pyplot as plt
N=1000
L=2

#1
daten_expo=expon.rvs(0,1/L,N)
daten_unif=uniform.rvs(-2,4,N)

x_u=np.linspace(-3,3,100)
plt.plot(x_u,uniform.pdf(x_u,-2,4),color='g',label="Dichtefunktion Unif")
x_e=np.linspace(0,4,100)
plt.plot(x_e, expon.pdf(x_e, 0, 1/L), color='b', label="Dichtefunktion Exp")
plt.legend()
plt.show()

#2
#Simulationen P(1 < X < 1.5)
expo_sim_p=np.mean((daten_expo>1) & (daten_expo<1.5))
unif_sim_p=np.mean((daten_unif>1) & (daten_unif<1.5))

#Theoretische P(1 < X < 1.5)
expo_theo_p=expon.cdf(1.5,0,1/L)-expon.cdf(1,0,1/L)
unif_theo_p=uniform.cdf(1.5,-2,4)-uniform.cdf(1,-2,4)

#3
expo_mean=np.mean(daten_expo)
unif_mean=np.mean(daten_unif)
expo_var=np.var(daten_expo)
unif_var=np.var(daten_unif)

print(f"Simuliert P(1 < X < 1.5) für Expo: {expo_sim_p:.4f}, Theoretisch: {expo_theo_p:.4f}")
print(f"Simuliert P(1 < X < 1.5) für Unif: {unif_sim_p:.4f}, Theoretisch: {unif_theo_p:.4f}")
print(f"Erwartungswert für Expo: {expo_mean:.4f}, Varianz: {expo_var:.4f}")
print(f"Erwartungswert für Unif: {unif_mean:.4f}, Varianz: {unif_var:.4f}")