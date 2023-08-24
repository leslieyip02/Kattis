n = int(input())
while n != 0:
    pts = [tuple(int(i) for i in input().split()) for _ in range (n)]
    p0 = pts[(n - 1) // 2]

    s = 0
    o = 0
    for pt in pts:
        if pt[0] == p0[0] or pt[1] == p0[1]:
            continue
        if (pt[0] - p0[0]) * (pt[1] - p0[1]) > 0:
            s += 1
        else:
            o +=1
    print(s, o)
    n = int(input())