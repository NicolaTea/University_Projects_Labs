#Man sch¨atze anhand Simulationen die Wahrscheinlichkeit, dass beim zweimaligen Werfen eines
#W¨urfels die Summe der Zahlen mindestens 7 ist (Summe ≥ 7),
#a) unter der Bedingung, dass beim ersten Wurf eine 4 erhalten wurde;
#b) unter der Bedingung, dass beim zweiten Wurf eine gerade Zahl erhalten wurde.
#c) Welche sind die theoretischen Wahrscheinlichkeiten bei a), bzw. b) ?
import numpy
N=1000
cA=0
cB=0
for i in range(N):
    first_roll=4
    second_roll=numpy.random.randint(1,7)
    if first_roll+second_roll>=7:
        cA=cA+1
print("Simulierte Wkt. für a):", cA / N)
for i in range(N):
    first_roll=numpy.random.randint(1,7)
    second_roll=numpy.random.choice([2,4,6])
    if first_roll+second_roll>=7:
        cB=cB+1
print("Simulierte Wkt. für a):", cB / N)
theoretical_a=sum([1 for second_roll in range(1,7) if 4+second_roll>=7])/6
theoretical_b=sum([
    (sum([1 for first_roll in range(1, 7) if first_roll + second_roll >= 7]) / 6)
    for second_roll in [2, 4, 6]
]) / 3
print("Theoretische Wkt. für a):", theoretical_a)
print("Theoretische Wkt. für b):", theoretical_b)