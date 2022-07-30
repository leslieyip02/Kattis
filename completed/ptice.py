a, b, c = 0, 0, 0
n = int(input())
ans = input()
for i in range(n):
    if ans[i] == "ABC"[i % 3]:
        a += 1
    if ans[i] == "BABC"[i % 4]:
        b += 1
    if ans[i] == "CCAABB"[i % 6]:
        c += 1
        
m = max(a, max(b, c))
print(m)
if a == m:
    print("Adrian")
if b == m:
    print("Bruno")
if c == m:
    print("Goran")
