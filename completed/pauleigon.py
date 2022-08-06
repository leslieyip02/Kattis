n, p, q = [int(i) for i in input().split(" ")]
print("paul" if ((p + q) // n) % 2 == 0 else "opponent")