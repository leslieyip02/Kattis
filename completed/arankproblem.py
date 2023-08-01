n, m = [int(i) for i in input().split()]

t = list(range(n))
for _ in range(m):
	t1, t2 = [int(i[1:]) - 1 for i in input().split()]
	i1, i2 = t.index(t1), t.index(t2)
	if i1 > i2:
		t = t[:i2] + t[i2 + 1:i1 + 1] + [t2] + t[i1 + 1:]

print(" ".join(f"T{i + 1}" for i in t))
