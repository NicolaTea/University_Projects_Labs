import random
from random import sample
import math
from math import perm,factorial
import itertools
from itertools import permutations,combinations,combinations_with_replacement
from more_itertools import distinct_permutations

print("-------------Ubung1------------")
#a) Man generiere alle Permutationen von sicher. Wie viele solche Permutationen gibt es?
#b) Man generiere zwei zufallige Permutationen von sicher.
#c) Man generiere alle Variationen je zwei Buchstaben aus dem String sicher. Wie viele solche Variationen gibt es?
#d) Welche ist die gesamte Anzahl der Variationen je 3 Buchstaben von MATHE?
#e) Man generiere alle Kombinationen (d.h. alle Anordnungen ohne Wiederholung,
# ohne Berucksichtigung der Reihenfolge) je 3 Buchstaben aus dem String MATHE"
#f) Welche ist die gesamte Anzahl der Kombinationen je 3 Buchstaben von MATHE?
wort="sicher"
perm=list(itertools.permutations(wort))
anzahl=len(perm)
print("a) ",anzahl) #a)
for p in perm[:2]:
    print("".join(p)) #b)
variationen=list(itertools.permutations(wort,2))
anzahl_variationen=len(variationen)
print("c) ",anzahl_variationen) #c)

wort2="MATHE"
var1=list(itertools.permutations(wort2,3))
anzahl_var1=len(var1)
print("d) ",anzahl_var1) #d)
var2=list(itertools.combinations(wort2,3))
anzahl_var2=len(var2)
print("f) ",anzahl_var2)
for k in var2[:10]:
    print("".join(k)) #e)

print("-------------Ubung2------------")
print("Permutation mit Wiederholung")
M=list(distinct_permutations("AABB"))
print(M)
m=len(M)
print("Anzahl Permutation von AABB mit Wiederholung: ",m)
for p in distinct_permutations("1112"):
    print("".join(p))
n=len(list(distinct_permutations("1112")))
print("Anzahl Permutationen von 1112 mit Wiederholung: ",n)

print("-------------Ubung3------------")
print("Kombination mit Wiederholung")
print("Alle Kombinationen von ABC je 2, mit Wiederholung")
comb=list(itertools.combinations_with_replacement("ABC",2))
for c in comb:
    print("".join(c))
k=len(comb)
print("Anzahl Kombinationen von ABC je 2 mit Wiederholung:",k)

print("-------------Ubung4------------")
#Wie viele Moglichkeiten gibt es 6 rote Kugeln in 4 Kartons aufzuteilen? Manche Kartons konnen leer
#bleiben. Man zahle alle moglichen Anordnungen auf. Hinweis: Wir bezeichnen die vier Kartons mit 1,2,3,4.
#Eine mogliche Anordnung ist: [1,1,2,3,3,3], d.h. 2 Kugeln im Karton ”1”, eine Kugel im Karton ”2”, 3 Kugeln
#im Karton ”3” und keine Kugel im Karton ”4”.

kugeln=6
karton=4
combination=list(itertools.combinations_with_replacement(range(1,karton+1),kugeln))
for comb in combination:
    print(comb)
print("Anzahl der Wkt: ",len(combination))
