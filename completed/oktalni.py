d = ["000", "001", "010", "011", "100", "101", "110", "111"]

b = input()
while len(b) % 3 != 0:
    b = '0' + b

for i in range(len(b) // 3):
    print(d.index(b[i * 3 : (i + 1) * 3]), end="")