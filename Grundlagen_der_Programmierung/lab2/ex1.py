numbers=[1,2,2,3,4,5,6,6,7,7,1]
unique=[]                    #initializam o lista noua
for number in numbers:
    if number not in unique:   #daca nu avem nr in lista noastra
        unique.append(number)   #adaugam in lista noua
print(unique)