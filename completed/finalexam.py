prev = ""
score = 0

for _ in range(int(input())):
    current = input()
    if current == prev:
        score = score + 1
    prev = current

print(score)