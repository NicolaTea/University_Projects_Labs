def prim_faktoren(n):
    factors=[] #lista factori
    while n%2==0:   #rezolvam cu factorul prim 2
        factors.append(2)
        n//=2
    for i in range(3,int(n**(1/2))+1,2):  #verificam daca factorii sunt primi
        while n%i==0:
            factors.append(i)
            n//=i
    if n>1:
        factors.append(n)
    return factors
n=int(input("Zahl: "))
result=prim_faktoren(n)
print("Primfaktoren von", n, "sind:", result)