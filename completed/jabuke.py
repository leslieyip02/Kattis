def area(p1, p2, p3):
    return abs(p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) + p3[0] * (p1[1] - p2[1])) / 2.0

pa = [int(i) for i in input().split(" ")]
pb = [int(i) for i in input().split(" ")]
pc = [int(i) for i in input().split(" ")]

a0 = area(pa, pb, pc)
print(f"{a0:.1f}")

n = int(input())
c = 0
for i in range(n):
    pi = [int(i) for i in input().split(" ")]

    if area(pa, pb, pi) + area(pa, pi, pc) + area(pi, pb, pc) == a0:
        c += 1

print(c)