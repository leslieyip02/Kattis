v = 7
for _ in range(int(input())):
    if input() == "Skru op!":
        v = min(v + 1, 10)
    else:
        v = max(v - 1, 0)
print(v)