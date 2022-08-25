b = []
for _ in range(7):
    ln = [i for i in input()]
    b.append(ln)

d = [(1, 0), (-1, 0), (0, 1), (0, -1)]
c = 0
for y0 in range(7):
    for x0 in range(7):
        if b[y0][x0] != 'o':
            continue

        for o in d:
            x1 = x0 + o[0]
            x2 = x0 + o[0] * 2
            y1 = y0 + o[1]
            y2 = y0 + o[1] * 2

            if (0 <= x1 < 7 and 0 <= x2 < 7 and
                0 <= y1 < 7 and 0 <= y2 < 7):

                if b[y1][x1] == 'o' and b[y2][x2] == '.':
                    c += 1

print(c)
