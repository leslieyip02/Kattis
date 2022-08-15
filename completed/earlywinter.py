n, dm = [int(i) for i in input().split(" ")]
d = [int(i) for i in input().split(" ")]

k = -1
for i in range(n):
    if d[i] <= dm:
        k = i
        break

if k == -1:
    print("It had never snowed this early!")
else:
    print(f"It hadn't snowed this early in {k} years!")