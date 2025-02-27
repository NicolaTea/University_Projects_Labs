import numpy
c1 ,c2 ,a1 ,a2=0,0,0,0
N= 10000
A= list ( range (1,21))
for _ in range (N):
    i= numpy . random . randint (len(A))
    v=A[i]
    c1=c1+(v%2)
    c2=c2+((v%2)==0)
    a1=a1+(v%2)*((v%3)==0)
    a2=a2+ ((v%2)==0)*(6<=v and v<=10)
p1=a1/c1
p2=a2/c2
p3=c1/N
print ("Aus den Simulationen :")
print (f"p1={p1 :.6f}","theor Wkt.: ",3/10) #bedingte Wkt eine zufallige zahl aus a ist teiblar durch 3,
# wenn man weiss die zahl ist ungerade
print (f"p2={p2 :.6f}","theor Wkt.: ",3/10) #bedingte Wkt eine zufallige zahl aus a ist zw 6 und 10,
# wenn man weiss die zahl ist gerade
print (f"p3={p3 :.6f}","theor Wkt.: ",10/20) #wkt zufallige zahl aus a ist ungerade