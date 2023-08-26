n = int(input())
for _ in range(n):
    k, w = [int(i) for i in input().split()]
    s = input()
    m = k
    for _ in range(w - 1):
        t = input()
        i = 0
        while i < k:
            if s[i:] == t[:k - i]:
                break
            i += 1
        m += i
        s = t
    print(m)
