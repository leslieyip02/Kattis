from math import pow, pi

r, m, c = [float(i) for i in input().split(" ")]
while r != 0 and m != 0 and c != 0:
    a1 = pi * pow(r, 2)
    a2 = pow(r * 2, 2) * (c / m)
    print(a1, a2)
    
    r, m, c = [float(i) for i in input().split(" ")]
