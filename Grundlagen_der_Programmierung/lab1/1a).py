def totprim(n):
  for i in range(2,n):  # numerele de la 2...
    prim=True
    for div in range(2,i): #divizori de la 2...
      if i % div ==0:     # daca exista un alt divizor inafara de 1 si el insusi
        prim=False
        break
    if prim == True:
      print(i)
n=int(input("n="))      # dam valoare
totprim(n)