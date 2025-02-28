def is_prime(x):
   if x == 2:
     return True
   if x < 2 or x % 2 == 0:
     return False

   for i in range(3, int(x ** (1 / 2)) + 1, 2):
      if x % i == 0:
       return False

   return True
def langste_prim_teilfolge(numbers):
    if not numbers:
        return []
    max_length=0
    max_teilfolge=[]

    current_length = 0
    current_teilfolge = []
    for number in numbers:
        if is_prime(number): #daca gasim nr prim
            current_length+=1
            current_teilfolge.append(number) #adaugam in lista
        else:
            if current_length > max_length: #verificam care e maximul
                max_length = current_length
                max_teilfolge = current_teilfolge
            current_length = 0
            current_teilfolge = []


    if current_length > max_length: #verificam care e maximul
      max_teilfolge = current_teilfolge

    return max_teilfolge

nums = [2, 6, 7, 8,9, 13, 14 , 17, 18, 19, 23, 29, 31, 37, 41]
result = langste_prim_teilfolge(nums)
print(result)