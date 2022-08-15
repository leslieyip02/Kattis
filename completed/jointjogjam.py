from math import pow, sqrt

def dist(x1, y1, x2, y2):
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))

xk1, yk1, xo1, yo1, xk2, yk2, xo2, yo2 = [int(i) for i in input().split(" ")]

d1 = dist(xk1, yk1, xo1, yo1)
d2 = dist(xk2, yk2, xo2, yo2)
while abs(d1 - d2) > 0.000001:
    if d1 > d2:
        xk2 = (xk1 + xk2) / 2
        yk2 = (yk1 + yk2) / 2
        xo2 = (xo1 + xo2) / 2
        yo2 = (yo1 + yo2) / 2 
    else:
        xk1 = (xk1 + xk2) / 2
        yk1 = (yk1 + yk2) / 2
        xo1 = (xo1 + xo2) / 2
        yo1 = (yo1 + yo2) / 2 

    d1 = dist(xk1, yk1, xo1, yo1)
    d2 = dist(xk2, yk2, xo2, yo2)

print(d1)