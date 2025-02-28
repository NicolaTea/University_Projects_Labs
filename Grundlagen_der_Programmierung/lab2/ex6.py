def domino(l):
    lun = 1
    lunmax = 1
    indice = 0

    for idx in range(0, len(l)-1):
        if lun > lunmax:    #verificam daca e maxim
            lunmax = lun
            indice = idx
        if l[idx] % 10 == l[idx+1]//10 % 10:  #daca ultima cifra din nr e egal cu prima cifra din celalalt nr
            lun +=1
        else:
            lun=1
    for i in range(indice - lunmax + 1, indice + 1): #de la primul indice al cele mai lungi secvente
         print (l[i])

l = [12, 23, 34, 45, 76, 67, 78, 89, 90]
domino(l)