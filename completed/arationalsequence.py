from math import pow

for _ in range(int(input())):
    k, f = input().split(" ")
    p, q = [int(i) for i in f.split(("/"))]

    if p < q:
        q -= p
        p += q
    else:
        p0  = p
        p = q
        q = q - p0 + 2 * (p0 // q) * q
   
    print(f"{k} {p}/{q}")
