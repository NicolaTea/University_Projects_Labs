def is_prime(x):
    if x ==2:
       return True
    if x%2==0 or x<2:
        return False
    for i in range(3,int(x**(1/2))+1,2):
        if x%i==0:
            return False
    return True
def langste_teilfolge_diff_prim(numbers):
    if not numbers:
        return []
    max_length=0
    max_teilfolge=[]
    current_length=0
    current_teilfolge=[]
    for i in range(1,len(numbers)):
        diff=abs(numbers[i]-numbers[i-1]) #initializam diferenta
        if is_prime(diff):
            current_length+=1
            current_teilfolge.append(numbers[i])
        else:
            if current_length> max_length:
                max_length=current_length
                max_teilfolge=current_teilfolge
            current_length=1
            current_teilfolge=[numbers[i]]
    if current_length>max_length:
            max_teilfolge=current_teilfolge
    return max_teilfolge
numbers=[2, 5, 11, 16, 21, 29, 34, 38, 43, 50, 53,76,83]
result = langste_teilfolge_diff_prim(numbers)
print(result)