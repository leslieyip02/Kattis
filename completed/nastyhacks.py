n = int(input())
for _ in range(n):
    r, e, c = [int(i) for i in input().strip().split(" ")]
    if r == e - c:
        print("does not matter")
    else:
        print(("do not " if e - c < r else "") + "advertise")


