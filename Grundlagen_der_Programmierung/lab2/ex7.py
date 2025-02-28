import math
def cmmmc(a,b):
    return a*b//math.gcd(a,b)
def find(l,frm,to):
    return cmmmc(l[frm],l[to])
l=[12,24,48,50]