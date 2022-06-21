letters = "abcdefghijklmnoprstuvwxyz"

keyphrase = input()
key = [[] for a in range(5)]
row = 0

# read input into 5 x 5 key grid
for letter in keyphrase:
    try:
        index = letters.index(letter)
        key[row].append(letter.upper())
        if len(key[row]) == 5:
            row = row + 1
        letters = letters.replace(letter, "")
    except:
        continue

for unused in letters:
    key[row].append(unused.upper())
    if len(key[row]) == 5:
            row = row + 1

unencrypted = input().upper().replace(" ", "")
digraphs = []

# split input text into digraphs
skip = False
for i in range(len(unencrypted)):
    if skip:
        skip = False
        continue
    elif unencrypted[i] == " ":
        continue
    elif i == len(unencrypted) - 1 or unencrypted[i] == unencrypted[i + 1]:
        digraph = unencrypted[i] + "X"
        digraphs.append(digraph)
    else:
        digraph = unencrypted[i] + unencrypted[i + 1]
        digraphs.append(digraph)
        skip = True

# encrypt
for digraph in digraphs:
    letter1, letter2 = digraph[0], digraph[1]
    
    for j in range(5):
        for i in range(5):
            if key[j][i] == letter1:
                x1, y1 = i, j
            elif key[j][i] == letter2:
                x2, y2 = i, j

    # same column
    if x1 == x2:
        print(key[(y1 + 1) % 5][x1], end="")
        print(key[(y2 + 1) % 5][x2], end="")
    # same row
    elif y1 == y2:
        print(key[y1][(x1 + 1) % 5], end="")
        print(key[y2][(x2 + 1) % 5], end="")
    # different row and column
    else:
        print(key[y1][x2], end="")
        print(key[y2][x1], end="")

print("\n")