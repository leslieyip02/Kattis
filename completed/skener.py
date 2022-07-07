r, c, zr, zc = [int(i) for i in input().split(" ")]

for _ in range(r):
    row = input()
    for _ in range(zr):
        for pixel in row:
            for _ in range(zc):
                print(pixel, end="")
        print()