#In einer Urne sind 6 rote Kugeln, 4 blaue Kugeln und 6 gr¨une Kugeln. Man zieht 3 Kugeln
#hintereinander ohne Zur¨ucklegen. Man betrachtet die Ereignisse:
#A:“mindestens eine rote Kugel wurde entnommen”
#B:“alle entnommenen Kugeln haben dieselbe Farbe”.
import random
kugeln=random.sample(["r","b","g"],counts=[6,4,6],k=3)
print(kugeln)
cA=0
cB=0
cAundcB=0
N=1000
for i in range(N):
    kugeln = random.sample(["r", "b", "g"], counts=[6, 4, 6], k=3)
    if "r" in kugeln:
        cA=cA+1
    if len(set(kugeln))==1:
        cB=cB+1
        if "r" in kugeln:
            cAundcB=cAundcB+1
print("Aus Simulation:P(A): ",cA/N,",P(B):",cB/N,",P(A und B):",cAundcB/N,",P(B|A):",cAundcB/cA)
#1-P(keine rote kugel)
wA=1-(10/16)*(9/15)*(8/14)
wB=(6/16)*(5/15)*(4/14)+(4/16)*(3/15)*(2/14)+(6/16)*(5/15)*(4/14) #alle 3 rot oder alle 3 blau oder alle 3 grun
wAundB=(6/16)*(5/15)*(4/14) # A und B=alle 3 kugeln sind rot
print ("Theoretische Wkt.:",f"P(A):{wA:.5f},P(B):{wB:.5f},P(A und B):{wAundB:.5f},P(B|A):{cAundcB/wA:.5f}")