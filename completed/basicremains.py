import sys

def divide(r, b):
    if not r:
        return

    divide(r // b, b)
    print(r % b, end="")

if __name__ == "__main__":
    sys.setrecursionlimit(2000)

    line = input()
    while line != "0":
        b, p, m = line.split(" ")
        base = int(b)

        divisor = 0
        for d in m:
            divisor = divisor * base + int(d)

        remainder = 0
        for d in p:
            remainder = remainder * base + int(d)
            remainder %= divisor

        if not remainder:
            print(0)
        else:
            divide(remainder, base)
            print()

        line = input()