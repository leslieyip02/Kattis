c = ["number of", "most", "fewest", "more", "fewer", "many", "few"]
m = ["amount of", "most", "least", "more", "less", "much", "little"]

s = {}
n, p = [int(i) for i in input().split(' ')]
for _ in range(n):
    x, y = input().strip().split(' ')
    s[x] = y

for _ in range(p):
    z = input().strip().split(' ')

    x = z[-1]
    y = s[x]
    z = ' '.join(z[:-1])
    
    ok = False
    if y == 'c':
        for q in c:
            if q == z:
                ok = True
                break
    else:
        for q in m:
            if q == z:
                ok = True
                break

    print("Correct!" if ok else "Not on my watch!")