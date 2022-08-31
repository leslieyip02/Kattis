pad = [('a', 'b', 'c'), ('d', 'e', 'f'), ('g', 'h', 'i'), ('j', 'k', 'l'), ('m', 'n', 'o'), ('p', 'q', 'r', 's'), ('t', 'u', 'v'), ('w', 'x', 'y', 'z')]

n = int(input())
words = []
for _ in range(n):
    words.append(input())
nums = [int(i) - 2 for i in input()]

c = 0
for word in words:
    if len(word) < len(nums):
        continue

    ok = True
    for i in range(len(word)):
        if word[i] not in pad[nums[i]]:
            ok = False
            break

    if ok:
        c += 1

print(c)
    