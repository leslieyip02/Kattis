e = [9, 4, 4, 4, 7]

ln = input()
while ln != '-':
    c0 = 0
    f0 = 0
    
    while ln != '-':
        nut = ln.split(" ")

        ci = 0
        pi = 0
        for i in range(5):
            if nut[i].find('g') != -1:
                ci += int(nut[i][:-1]) * e[i]
            elif nut[i].find('C') != -1:
                ci += int(nut[i][:-1])
            else:
                pi += int(nut[i][:-1])

        ci = ci / (100 - pi) * 100
        c0 += ci

        if nut[0].find('g') != -1:
            f0 += int(nut[0][:-1]) * 9
        elif nut[0].find('C') != -1:
            f0 += int(nut[0][:-1])
        else:
            f0 += ci * int(nut[0][:-1]) / 100

        ln = input()

    print(f"{round(f0 / c0 * 100)}%")

    ln = input()
