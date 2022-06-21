tx, ty = 0, 0
max_x, max_y = 0, 0
grid = {}

offsets = [(1, 2), (-1, 2), (1, -2), (-1, -2), (2, 1), (-2, 1), (2, -1), (-2, -1)]

# move by ox and oy
def fly_to(ix, iy, ox, oy):
    if ix == tx and iy == ty:
        return 0

    grid[iy][ix] = False

    # vertical -> horizontal
    v = True
    vx, vy = ix, iy 
    for _ in range(abs(oy)):
        if v:
            vy = vy + (1 if oy > 0 else -1)
            while grid.get(vy, {}).get(ix, -1) == -1:
                if vy > max_y or vy <= 0:
                    v = False
                    break
                vy = vy + (1 if oy > 0 else -1)

    for _ in range(abs(ox)):
        if v:
            vx = vx + (1 if ox > 0 else -1)
            while grid[vy].get(vx, -1) == -1:
                if vx > max_x or vx <= 0:
                    v = False
                    break
                vx = vx + (1 if ox > 0 else -1)

    if v and grid[vy][vx]:
        m = fly_everywhere(vx, vy)
        if m >= 0:
            return m + 1

    # horizontal -> vertical
    h = True
    hx, hy = ix, iy
    for _ in range(abs(ox)):
        if h:
            hx = hx + (1 if ox > 0 else -1)
            while grid[iy].get(hx, -1) == -1:
                if hx > max_x or hx <= 0:
                    h = False
                    break
                hx = hx + (1 if ox > 0 else -1)

    for _ in range(abs(oy)):
        if h:
            hy = hy + (1 if oy > 0 else -1)
            while grid.get(hy, {}).get(hx, -1) == -1:
                if hy > max_y or hy <= 0:
                    h = False
                    break
                hy = hy + (1 if oy > 0 else -1)

    if h and grid[hy][hx]:
        m = fly_everywhere(hx, hy)
        if m >= 0:
            return m + 1

    return -1

def fly_everywhere(ix, iy):
    for o in offsets:
        m = fly_to(ix, iy, o[0], o[1])
        if m >= 0:
            return m
    return -1

def main():
    n = int(input().strip())
    global tx, ty, max_x, max_y
    sx, sy, tx, ty = [int(i) for i in input().strip().split(" ")]

    for _ in range(n):
        x, y, = [int(i) for i in input().strip().split(" ")]
        
        grid[y] = grid.get(y, {})
        grid[y][x] = True

        max_x = max(x, max_x)
        max_y = max(y, max_y)

    m = fly_everywhere(sx, sy)
    print(m)

if __name__ == "__main__":
    main()
