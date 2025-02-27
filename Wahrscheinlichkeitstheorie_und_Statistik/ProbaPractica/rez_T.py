import random
import matplotlib.pyplot as plt
import numpy as np

num_felder=5
num_spins=3
X=[]
N=1000
for _ in range(N):
    spins=[random.randint(1,num_felder) for _ in range(num_spins)]
    total_score=0
    for spin in spins:
        if spin==1:
            total_score+=5
        elif spin == 2:
            total_score += 0
        elif spin == 3:
            total_score += -1
        elif spin == 4:
            total_score += -2
        elif spin == 5:
            total_score += -3
    X.append(total_score)


#P(X=3)
P_sim_3=np.mean([x==3 for x in X])
print(" Aus Simulationen P(X=3):",P_sim_3)
#P(X=-6)
P_sim_6=np.mean([x==-6 for x in X])
print(" Aus Simulationen P(X=-6):",P_sim_6)

#Erwartungswert
e_x=np.mean(X)
#Var
v_x=np.var(X)
print(f"E(X): {e_x:.4f}")
print(f"Var(X): {v_x:.4f}")

theoretical_3=(
        (1/5*4/5*4/5)+ #gewinn,verlust,verlust
        (4/5*4/5*1/5)+ #verlust,verlust,gewinn
        (4/5*1/5*4/5) #verlust,gewinn,verlust
)

# Cazuri posibile:
# 1. (-3, -3, 0)
# 2. (-3, 0, -3)
# 3. (0, -3, -3)
# 4. (-3, -2, -1)
theoretical_6=(
    3*((4/5*4/5*4/5))+ # cazul cu doua -3 și un 0
    6*((1/5) * (1/5) * (1/5)) #cazul cu -3 -2,-1->toate permutarile

)
z,count=np.unique(X,return_counts=True)
plt.bar(z,count/N,width=0.9, color="red", edgecolor="black", label="relative Haufigkeiten")
z_theoretical = [3, -6]
p_theoretical = [theoretical_3, theoretical_6]
plt.bar(z_theoretical, p_theoretical, width=0.5, color="blue", edgecolor="black", alpha=0.6, label="Theoretische Wkt")
plt.legend(loc="upper right")

plt.show()


