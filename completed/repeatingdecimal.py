import sys

for line in sys.stdin:
    a, b, c = [int(i) for i in line.strip().split(" ")]    

    print("0.", end="")
    for _ in range(c):
        if a == 0:
            print(0, end="")
            continue

        d = 1
        
        if a < b:
            a *= 10
            d = a // b

        a -= d * b

        print(d, end="")

    print()