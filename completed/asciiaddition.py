n = [
    "xxxxxx...xx...xx...xx...xx...xxxxxx",
    "....x....x....x....x....x....x....x",
    "xxxxx....x....xxxxxxx....x....xxxxx",
    "xxxxx....x....xxxxxx....x....xxxxxx",
    "x...xx...xx...xxxxxx....x....x....x",
    "xxxxxx....x....xxxxx....x....xxxxxx",
    "xxxxxx....x....xxxxxx...xx...xxxxxx",
    "xxxxx....x....x....x....x....x....x",
    "xxxxxx...xx...xxxxxxx...xx...xxxxxx",
    "xxxxxx...xx...xxxxxx....x....xxxxxx",
    ".......x....x..xxxxx..x....x......."
]

ln = input()
art = ["" for _ in range(len(ln) // 5)]

for i in range(len(ln) // 5):
    art[i] += ln[i * 6 : i * 6 + 5]

for i in range(1, 7):
    ln = input()
    for j in range(len(ln) // 5):
        art[j] += ln[j * 6 : j * 6 + 5]

a = ""
b = ""
for d in art:
    if len(d) == 0:
        break

    i = n.index(d)
    if i == 10:
        a = int(a)
        continue

    if type(a) == str:
        a += str(i)
    else:
        b += str(i)

c = str(a + int(b))
ans = ["" for _ in range(7)]
for i in range(7):
    ln = ""

    for d in c:
        ln += n[int(d)][i * 5 : (i + 1) * 5] + "."

    print(ln[:-1])
