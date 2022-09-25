bank = set()

n = int(input())
for _ in range(n):
    w = input().lower().replace('-', ' ')
    bank.add(w)

print(len(bank))
