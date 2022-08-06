word = input()
freq = {}

for letter in word:
    freq[letter] = freq.get(letter, 0) + 1

r = 0 if (all(f % 2 == 0 for f in freq.values())) else -1
for f in freq.values():
    if (f % 2 == 1):
        r += 1

print(r)