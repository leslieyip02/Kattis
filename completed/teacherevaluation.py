n, p = [int(i) for i in input().split(' ')]
s = [int(i) for i in input().split(' ')]

c = 0
if p == 100 or sum(s) / len(s) > p:
    c = "impossible"
else:
    while sum(s) / len(s) < p:
        s.append(100)
        c += 1;
        
print(c)