s = [3 ** i for i in range(100)]

n = int(input())
while n != 0:
    n -= 1

    i = 0
    sn = []
    while n > 0:
        if n & 1:
            sn.append(str(s[i]))
            
        n >>= 1
        i += 1
        
    print(f"{{ {', '.join(sn)} }}")

    n = int(input())