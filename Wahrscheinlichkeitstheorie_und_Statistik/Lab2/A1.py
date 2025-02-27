import numpy
#1) a) Man schatze durch wiederholte Simulationen die Wahrscheinlichkeit von dem Ereignis
#A: in einer Gruppe von k = 23 Personen mindestens zwei Personen haben den gleichen Geburtstag.
#Annahme: Das Jahr hat n = 365 Tage.
#b) Man berechne (in Python) die theoretische Wahrscheinlichkeit P(A) ?
k=23 #personen
n=365 #tage
c=0
N=1000
for _ in range(N):
    G=numpy.random.randint(low=1,high=n+1,size=k)
#print(G)
#print(set(G))->doar numere unice nu se repeta aceeasi zi de mai multe ori
    if len(set(G))<k:
        c=c+1 #zahlt
print("P(A) aus Simulationen: ",c/N)
p=1
for i in range(k):
    p=p*(1-i/n)
p=1-p
print("P(A) theoretische Wkt: ",p)

