def choose(n, x=0, y=0):
    if n == []:
        return { x + y }

    w = choose(n[1:], x, int(str(y) + str(n[0])))
    if y == 0:
        w |= choose(n[1:], x + n[0], 0)
    else:
        w |= choose(n[1:], x + int(str(y) + str(n[0])), 0)
    return w

n = [int(i) for i in input().split("+")]
print(len(choose(n)))
