x, y, n = [int(i) for i in input().strip().split(" ")]

for i in range(1, n + 1):
    out = ""

    if (i % x == 0):
        out = "Fizz"
    if (i % y == 0):
        out = out + "Buzz"

    if len(out) == 0:
        out = i

    print(out)