n = int(input())
while n != 0:
    sizes = {
        "small": [],
        "medium": [],
        "large": []
    }

    for _ in range(n):
        ln = input().split(" ")
        sizes[ln[-1]].append({
            "x1": float(ln[0]),
            "y1": float(ln[1]),
            "x2": float(ln[2]),
            "y2": float(ln[3])
        })

    m = int(input())
    for _ in range(m):
        ln = input().split(" ")
        s = ln[-1]
        x, y = [float(i) for i in ln[:-1]]

        result = "floor"
        for b in sizes[s]:
            if (b["x1"] <= x <= b["x2"] and
                b["y1"] <= y <= b["y2"]):
                result = "correct"
                break

        if result == "floor":
            for si in sizes.keys():
                if si == s:
                    continue

                for b in sizes[si]:
                    if (b["x1"] <= x <= b["x2"] and
                        b["y1"] <= y <= b["y2"]):
                        result = si
                        break

                if result != "floor":
                    break
        print(s, result)

    print()
    n = int(input())
