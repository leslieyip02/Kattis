from math import sqrt, sin, acos, pi

while True:
    try:
        r, x, y = [float(i) for i in input().split(" ")]
        
        d = sqrt(x ** 2 + y ** 2)
        if d >= r:
            print("miss")
            continue
        else:
            a = acos(d / r)
            t = 0.5 * (r ** 2) * sin(2 * a)
            c = pi * (r ** 2)
            p = (r ** 2) * a - t
            q = c - p
            print(q, p)
            
    except:
        quit()