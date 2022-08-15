h, t = [int(i) for i in input().split(" ")]
while h != 0 and t != 0:
    s = 0

    if t % 2 == 1:
        t += 1
        s += 1

    while (h + t // 2) % 2 != 0:
        t += 2
        s += 2

    s += t // 2
    s += (h + t // 2) // 2
    print(s)

    h, t = [int(i) for i in input().split(" ")]