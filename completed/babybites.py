n = int(input())
a = input().split()

ok = True
for i in range(n):
    try:
        if int(a[i]) != i + 1:
            ok = False
            break
    except:
        continue

print("makes sense" if ok else "something is fishy")