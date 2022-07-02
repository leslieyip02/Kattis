from math import sqrt

a, b, c, d = [int(i) for i in input().split(" ")]
s = (a + b + c + d) / 2
print(sqrt((s - a) * (s - b) * (s - c) * (s - d)))