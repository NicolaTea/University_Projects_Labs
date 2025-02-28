def verschlussen(l):
    for index in range(1,len(l)):
        l[index]=[ 1+l[index] ]
    return l
n=[1,2,3,4]
print(verschlussen(n))