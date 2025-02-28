def ersten_primzahlen(n):
    primes = []  #o lista pt nr prime
    num = 2      #primu nr prim

    while len(primes) < n:
        is_prime = True
        for p in primes:
            if p * p > num:
                break
            if num % p == 0:  #am gasit alt divizor
                is_prime = False
                break
        if is_prime:
            primes.append(num) #adaugam in lista
        num += 1

    return primes


n=int(input("Zahl: "))
print("Die ersten Primzahlen sind: ",ersten_primzahlen(n))