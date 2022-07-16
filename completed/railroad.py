x, y = [int(i) for i in input().split(" ")]
print("possible" if (x * 4 + y * 3) % 2 == 0 else "impossible")