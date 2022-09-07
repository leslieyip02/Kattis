for _ in range(int(input())):
    st = input()
    cnt = input()
    a = int(cnt.split(" ")[0])
    
    n = []
    while len(n) < a:
        ln = input().split(" ")
        if len(ln) == 1:
            n.append(ln[0])
        else:
            _, p, q, r = ln
            for i in range(int(p), int(q) + 1, int(r)):
                n.append(str(i))
                
    x = [0 for i in range(10)]
    for m in n:
        for d in m:
            x[int(d)] += 1
    z = sum(x)

    print(f"{st}\n{cnt}")
    for y in range(10):
        print(f"Make {x[y]} digit {y}")
    print(f"In total {z} {'digit' if z == 1 else 'digits'}")