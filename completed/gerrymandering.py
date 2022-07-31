p, d = [int(i) for i in input().split(" ")]
districts = [[0, 0] for _ in range(d)]

v = 0
for _ in range(p):
    di, a, b = [int(i) for i in input().split(" ")]
    v += a + b
    districts[di - 1][0] += a
    districts[di - 1][1] += b

wa0 = 0
wb0 = 0
for district in districts:
    if district[0] > district[1]:
        wa = district[0] - ((district[0] + district[1]) // 2 + 1)
        wb = district[1]
        print(f"A {wa} {wb}")
    else:
        wa = district[0]
        wb = district[1] - ((district[0] + district[1]) // 2 + 1)
        print(f"B {wa} {wb}")

    wa0 += wa
    wb0 += wb

print(abs(wa0 - wb0) / v)