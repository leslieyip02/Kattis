def chars(w):
    c = {}
    for i in w:
        c[i] = c.get(i, 0) + 1
    return c


def anagram(w):
    d = chars(w[0])
    for i in w[1:]:
        if chars(i) != d:
            return False
    return True


s = input()
multigram = False
ok = True
while ok:
    ok = False
    for i in range(1, len(s)):
        if len(s) % i != 0:
            continue

        w = [s[i * j : i * (j + 1)] for j in range(len(s) // i)]
        if anagram(w):
            multigram = True
            ok = True
            s = w[0]
            break

print(s if multigram else -1)