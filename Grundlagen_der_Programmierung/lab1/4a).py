def Quadratwurzel(x): #4a) cel mai apropiat nr a unei  radacini patrate a unui nr real

  if x < 0:
    print("Die Zahl ist negativ.")
  elif x == 0:
    print("alt numar")
  else:
    n = 1
    while x > n*n:
      n = n + 1 #n+=1
    print("Der angenaherten Wert der Quadratwurzel ist ")
    print(n)

Quadratwurzel(float(input("Zahl: ")))