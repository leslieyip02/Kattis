str = input()
halves = [str[:int(len(str) / 2)], str[int(len(str) / 2):]]
rotated_halves = []

for half in halves:
    r = 0
    for letter in half:
        r = r + ord(letter) - 65

    rotated = ""
    for letter in half:
        rotated += chr((ord(letter) - 65 + r) % 26 + 65)
    rotated_halves.append(rotated)

for l1, l2 in zip(*rotated_halves):
    print(chr((ord(l1) + ord(l2) - 130) % 26 + 65), end="")
print('\n')