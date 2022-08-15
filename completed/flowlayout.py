m = int(input())
while m != 0:
    w = w0 = 0
    h = h0 = 0

    x, y = [int(i) for i in input().split(" ")]
    while x != -1 and y != -1:
        if w + x > m:
            w0 = max(w, w0)
            h0 += h
            w = h = 0

        w += x
        h = max(y, h)

        x, y = [int(i) for i in input().split(" ")]

    w0 = max(w, w0)
    h0 += h

    print(f"{w0} x {h0}")

    m = int(input())