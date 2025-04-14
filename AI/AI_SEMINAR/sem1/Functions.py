def myfun(x,y):
    print("The function is executed.")
    y[0]=8 # This changes the list that y points to
    return(y[1]+x)

mylist = [1,2,3]
result=myfun(17,mylist)
print("Function returned: ",result)
print("List is now: ",mylist)

#List comprehensions
# List of all multiples of 3 that are <100:
evens = [x for x in range(3,100) if x%3==0]
print(evens)