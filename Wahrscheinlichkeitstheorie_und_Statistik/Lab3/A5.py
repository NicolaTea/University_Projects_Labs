#Welche ist die Wahrscheinlichkeit, dass in einer Gruppe von 5 Personen genau zwei Personen
#Geburtstag im selben Monat haben und die anderen drei Personen verschiedene Geburtstage haben?
#a) Man l¨ose die Aufgabe anhand Simulationen. b) Man gebe die theoretische Wahrscheinlichkeit an.
#Annahme: die Wahrscheinlichkeit, dass eine zuf¨allig gew¨ahlte Person Geburtstag in einem
#bestimmten Monat hat ist 1/12 .
import numpy
N=1000
c=0
for i in range(N):
    Geb=numpy.random.randint(low=1,high=13,size=5)
    if len(set(Geb))==4:
        c=c+1
print("Aus Simulationen Wkt.:",c/N)

print("Theo Wkt.:",10*12*11*10*9/(12**5))