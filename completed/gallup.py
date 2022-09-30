def normal_round(n, dp = 0):
    if dp == 0:
        return int(n + 0.5)
    else:
        v = 10 ** dp
        return int(n * v + 0.5) / v

t = 1
ln = input()
while ln != '0':
    ln = ln.split(' ')
    n = int(ln[0])
    
    # actual percentages 
    ap = [float(x) for x in ln[1:]]
    
    # decimal places
    dp = len(ln[1].split('.')[1]) if '.' in ln[1] else 0
    
    # base
    b = normal_round(sum(ap))

    res = "error"
    for ppl in range(1, 10000):
        # number of ppl for each option
        npe = [normal_round(i * ppl / b) for i in ap]
        
        # if sums don't match,
        if sum(npe) != ppl:
            continue

        # calculated percentages
        cp = [normal_round(i * 100 / ppl, dp) for i in npe]
        

        # compare
        ok = True
        for a, c in zip(ap, cp):
            if a != c:
                ok = False
                break
                
        if ok:
            res = ppl
            break

    print(f"Case {t}: {res}")
    t += 1

    ln = input()