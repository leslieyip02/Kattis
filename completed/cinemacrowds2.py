n, m = [int(i) for i in input().split(" ")]

q = [int(i) for i in input().split(" ")]
i = 0
while i < m:
    g = q[i]
    n -= g
    if n < 0:
        break
    
    i += 1

print(m - i)