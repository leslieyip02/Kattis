t = 1
ln = input()
while ln != '0':
    ln = ln.split(' ')
    r = [float(i) for i in ln[1:]]
    n = sum(r)
    p = len(ln[1].split('.')[1]) if '.' in ln[1] else 0

    for i in range(1, 10000):
        ok = True

        # a = []
        s = 0
        for f in r:
            x = round(f / 100.0 * i)
            y = round(x / i * 100, p)

            if y != f:
                ok = False
                break
            s += x

            # a.append((x, y, f))


        # s = n / s
        # print(s)

        if ok and s / i * 100 == n:
            # print(i, a, s)
            print(f"Case {t}: {i}")
            break

    t += 1
    ln = input()