def gross(l):
    numar = 0
    indice = 0
    while len(l) != 0: #avem elemente in lista
        max = 0  #valoarea maxima din lista
        for idx in range(0,len(l)):
            if l[idx] > max:
                max = l[idx]  #elementul maxim
                indice = idx  #pozitia elementului
        numar = numar * 100 + max
        l.pop(indice)
    return numar

l = [56,7,95,41,32,8]
result = gross(l)
print(result)