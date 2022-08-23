import sys


def fly_from(x1, y1):
    new_starters = []
    
    for o1 in (2, -2):
        if len(rows[y1]) > 2:
            x2_i = rows[y1].index(x1) + o1
            if 0 <= x2_i < len(rows[y1]):
                x2 = rows[y1][x2_i]

                if len(cols[x2]) > 1:
                    for o2 in (1, -1):
                        y2_i = cols[x2].index(y1) + o2
                        if 0 <= y2_i < len(cols[x2]) :
                            y2 = cols[x2][y2_i]
                            if cells[(x2, y2)] == -1:
                                cells[(x2, y2)] = cells[(x1, y1)] + 1
                                if x2 == tx and y2 == ty:
                                    return []
                                else:
                                    new_starters.append((x2, y2))

        if len(cols[x1]) > 2:
            y3_i = cols[x1].index(y1) + o1
            if 0 <= y3_i < len(cols[x1]):
                y3 = cols[x1][y3_i]

                if len(rows[y3]) > 1:
                    for o2 in (1, -1):
                        x3_i = rows[y3].index(x1) + o2
                        if 0 <= x3_i < len(rows[y3]):
                            x3 = rows[y3][x3_i]
                            if cells[(x3, y3)] == -1:
                                cells[(x3, y3)] = cells[(x1, y1)] + 1
                                if x3 == tx and y3 == ty:
                                    return []
                                else:
                                    new_starters.append((x3, y3))
                        
    return new_starters
    
def main():
    global cells, rows, cols, tx, ty, found

    n = int(sys.stdin.readline().strip())
    sx, sy, tx, ty = map(int, sys.stdin.readline().strip().split())

    starters = set()
    cells = {}
    rows = {}
    cols = {}

    while n > 0:
        n = n - 1
        x, y = map(int, sys.stdin.readline().strip().split())
 
        cells[(x, y)] = -1
        rows[y] = rows.get(y, [])
        rows[y] += x,
        cols[x] = cols.get(x, [])
        cols[x] += y,

    cells[(sx, sy)] = 0
    starters.add((sx, sy))
    while len(starters) > 0:
        new_starters = set()
        for starter in starters:
            new_starters.update(fly_from(*starter))
        starters = new_starters

    sys.stdout.write(f"{cells[(tx, ty)]}\n")
    return

if __name__ == "__main__":
    main()