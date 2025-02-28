import math
def prim_zu_n(n):
    primes=[]
    for i in range(1,n):
        if math.gcd(i,n)==1: #cel mai mare divizor comun
            primes.append(i)
    return primes
num=int(input("num= "))
result = prim_zu_n(num)
print(f"Die Zahlen, die relativ prim zu {num} sind: {result}")