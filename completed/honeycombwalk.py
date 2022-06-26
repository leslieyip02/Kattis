# https://nordic.icpc.io/ncpc2006/ncpc2006solutions.pdf

hive = {}

def w(x, y, s):
    if s == 0:
        return 1 if x == 0 and y == 0 else 0

    if hive.get((x + 14, y + 14), {}).get(s, -1) != -1:
        return hive[(x + 14, y + 14)][s]

    o =   w(x - 1, y - 1, s - 1) \
        + w(x - 1, y    , s - 1) \
        + w(x    , y - 1, s - 1) \
        + w(x + 1, y    , s - 1) \
        + w(x    , y + 1, s - 1) \
        + w(x + 1, y + 1, s - 1)

    hive[(x + 14, y + 14)] = hive.get((x + 14, y + 14), {})
    hive[(x + 14, y + 14)][s] = o

    return o

def main():
    for _ in range(int(input())):
        n = int(input())
        print(w(0, 0, n))

if __name__ == "__main__":
    main()