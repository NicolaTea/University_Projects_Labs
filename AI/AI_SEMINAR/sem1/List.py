li=[17,"Hello",4.1,"Bar",5,6]
print(li[2]) #4.1
print(li[-2]) #5
print(li[2:4]) #[4.1, 'Bar']

# Boolean test whether a value is in a list: the in operator
t = [1,2,3,4]
print(2 in t)

# Concatenate lists: the + operator
a = [1,2,3,4]
b = [5,6,7]
c = a + b
print(c)

# Repeat a list n times: the * operator
a=[1,2,3]
print(3*a)

# Append lists
a=[1,2,3]
a.append(4)

# Index of first occurence
a.index(2)

# Number of occurences
a = [1,2,3,2,1,2]
a.count(2)

# Remove first occurence
a.remove(2)

# Revese the list
a.reverse()

# Sort the list
a.sort()
