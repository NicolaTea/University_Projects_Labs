def is_prime(x):
    if x ==2:
        return True
    if x<2 or x%2==0:
        return False
    for i in range(3, int(x**(1/2))+1,2):
        if x%i==0:
            return False
    return True

def langste_teilfolge_summe_prim(numbers):
    if not numbers:
        return []
    max_lenght=0
    max_teilfolge=[]
    current_length=0
    current_teilfolge=[]
    for i in range(1,len(numbers)):
        sum=abs(numbers[i]+numbers[i-1]) #initializam suma
        if is_prime(sum):
            current_length+=1
            current_teilfolge.append(numbers[i])
        else:
            if current_length>max_lenght:
                max_lenght=current_length
                max_teilfolge=current_teilfolge
            current_length=1
            current_teilfolge=[numbers[i]]
    if current_length>max_lenght:
        max_teilfolge=current_teilfolge
    return max_teilfolge
numbers=[2, 3, 7, 9, 14 ,23, 13, 17, 24, 29, 31, 37, 41]
result=langste_teilfolge_summe_prim(numbers)
print(result)