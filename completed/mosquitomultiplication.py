while True:
    try:
        m, p, l, e, r, s, n = [int(i) for i in input().split(" ")]

        for _ in range(n):
            m0 = m
            m = p // s
            p = l // r
            l = m0 * e
        print(m)

    except:
        break