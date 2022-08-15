x = int(input())
while x >= 10:
    p = 1
    for d in [int(i) for i in str(x)]:
        if d != 0:
            p *= d
    x = p
            
print(p)