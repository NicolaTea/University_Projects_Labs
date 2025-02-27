import random
import numpy as np
def Simulation_Ziehung():
    urne=[0]*4+[1]*6 #0 fur weisse, 1 fur schwarze Kugeln
    Ziehung_schwarz=0
    for _ in range(3): #hochstens drei Ziehungen
        kugel=random.choice(urne)
        urne.remove(kugel)
        if kugel==1: #schwarze Kugel
            Ziehung_schwarz+=1
        else:
            break
    return Ziehung_schwarz

N=1000
x=[Simulation_Ziehung() for _ in range(N)]
#print(x)

#Calculate the (theoretical) probability of winning a game
prob_distributions={i:x.count(i)/N for i in range(4)}
print(f"Probability of winning a game: {prob_distributions}")

def calculate_score(x):
    if x == 3:
        return 30
    elif x == 2:
        return 25
    else:
        return - 5
#print(sum/N)

average_score=np.mean([calculate_score(i) for i in x])
print(f"Avergae score of the player: {average_score}")