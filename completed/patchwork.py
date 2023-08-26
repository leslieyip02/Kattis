r, c = [int(i) for i in input().split()]
q = [["." for _ in range(c)] for _ in range(r)]

n = int(input())
p = []
for _ in range(n):
	r, _ = [int(i) for i in input().split()]
	p.append([input() for _ in range(r)])

m = int(input())
for _ in range(m):
	x, y, z = [int(i) for i in input().split()]
	for i, r in enumerate(p[z - 1]):
		if x + i >= len(q):
			break

		for j, c in enumerate(r):
			if y + j >= len(q[0]):
				continue
			q[x + i][y + j] = c

for i in q:
	print("".join(i))
