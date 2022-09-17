n = int(input())

log = {}
for _ in range(n):
    fn, ln, cse = input().split(" ")
    log[cse] = log.get(cse, set())
    log[cse].add(f"{fn} {ln}")

for cse in sorted(log):
    print(f"{cse} {len(log[cse])}")
