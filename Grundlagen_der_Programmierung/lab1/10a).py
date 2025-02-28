def is_prime(x):
   if x == 2:
     return True
   if x < 2 or x % 2 == 0:
     return False

   for i in range(3, int(x ** (1 / 2)) + 1, 2):
      if x % i == 0:
       return False
   return True

def goldbachs_vermutung(n):
    if n<=2 or n%2!=0:      #verificam n fata de 2
        return None
    for i in range(2,n//2+1):
        j=n-i
        if is_prime(i) and is_prime(j): #verificam daca sunt prime
            return (i,j)

    return None
num=int(input("num= "))
result=goldbachs_vermutung(num)
print(result)