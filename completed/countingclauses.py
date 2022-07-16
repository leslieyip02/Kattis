clauses = set()
m, n = [int(i) for i in input().split(" ")]
for _ in range(m):
    clauses.add(input())

print("satisfactory" if len(clauses) >= 8 else "unsatisfactory")