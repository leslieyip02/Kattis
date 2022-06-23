import sys
from bisect import insort

def can_fly_to(x1, y1, x2, y2):
    # check for the number of clear cells
    # along L shape path between point

    # print(f"Checking {x1, y1, x2, y2}")
    
    # horizontal -> vertical
    # check corner exists
    if y1 in cols.get(x2):
        try:
            # print(rows[y1], rows[y1].index(x2), rows[y1].index(x1))
            # print(cols[x1], cols[x2].index(y2), cols[x2].index(y1))
            # check there are 2 clear cells along horizontal
            # and 1 clear cell along vertical
            w = abs(rows[y1].index(x2) - rows[y1].index(x1))
            h = abs(cols[x2].index(y2) - cols[x2].index(y1)) 
            if ((w == 2 and h == 1) or
                (w == 1 and h == 2)):
                return True 
        except ValueError:
            pass

    # vertical -> horizontal
    if x1 in rows.get(y2):
        try:
            # print(cols[x1], cols[x1].index(y2), cols[x1].index(y1))
            # print(rows[y2], rows[y2].index(x2), rows[y2].index(x1))
            w = abs(cols[x1].index(y2) - cols[x1].index(y1))
            h = abs(rows[y2].index(x2) - rows[y2].index(x1))
            if ((w == 2 and h == 1) or
                (w == 1 and h == 2)):
                return True 
        except ValueError:
            pass

    return False

def main():
    global cells, rows, cols
    
    n = int(sys.stdin.readline().strip())
    sx, sy, tx, ty = map(int, sys.stdin.readline().strip().split())

    # track coordinates + number of moves needed to get to point
    # -1 number of moves means the cell has not been accessed yet
    cells = []
    rows = {}
    cols = {}
    
    # keep track of cells that can start tracing from
    starters = []

    for i in range(n):
        x, y = map(int, sys.stdin.readline().strip().split())
        
        if x == sx and y == sy:
            cells.append([x, y, 0])
            starters.append(cells[i])
        else:
            cells.append([x, y, -1])

        try:
            insort(rows[y], x)
        except KeyError:
            rows[y] = [x]

        try:
            insort(cols[x], y)
        except KeyError:
            cols[x] = [y]

    # only keep looping if new cells are traced into
    while len(starters) > 0:
        new_starters = []
        # only search for new cells from cells that have been accessed
        for starter in starters:
            for i in range(len(cells)):
                if can_fly_to(starter[0], starter[1], cells[i][0], cells[i][1]):
                    # for cells that have been traced into, check if there's a shorter path
                    if cells[i][2] > 0:
                        if starter[2] + 1 < cells[i][2]:
                            cells[i][2] = starter[2] + 1
                            # look through cell again
                            new_starters.append(cells[i])
                    # check cells that haven't been accessed yet
                    elif cells[i][2] == -1:
                        cells[i][2] = starter[2] + 1
                        new_starters.append(cells[i])
        
        starters = new_starters
        # print(starters)

    for cell in cells:
        if cell[0] == tx and cell[1] == ty:
            print(cell[2])
            return

if __name__ == "__main__":
    main()
