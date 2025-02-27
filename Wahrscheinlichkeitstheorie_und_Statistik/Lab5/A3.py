import random
import numpy as np
N=1000
x=[-6,6] #Verlust/Gewinn
p=1-((12*11*10*9*8*7)/(12**6)) #theoretische Wkt. fur Gewinn
P=[1-p,p]
Zfg_Zahlen=random.choices(x,weights=P,k=N)
print("die Wkt, mit welcher Prof .X eine Werte gewinnt, ist",p)
#print(Zfg_Zahlen)
print("anhand Simulationen gewinnt der Professor im Durchschnitt",np.mean(Zfg_Zahlen), "Euro")
print(f"theoretischer Erwartungswert ist {(sum(x[i]*P[i] for i in range(len(x)))):.6f}")

