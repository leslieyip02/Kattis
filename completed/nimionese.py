def is_hard(c):
    return c.lower() in "bcdgknpt"

def nearest_hard(c):
    i = ord(c)
    
    for j in range(1, 26):
        k = chr(i - j)
        if (is_hard(k)):
            return k

        k = chr(i + j)
        if (is_hard(k)):
            return k

line = input()
for word in line.split(" "):
    syllables = [[c for c in syllable] for syllable in word.split("-")]

    c = syllables[0][0]
    if not is_hard(c):
        c = nearest_hard(c)

    syllables[0][0] = c
    c = c.lower()
    for syllable in syllables[1:]:
        for i, letter in enumerate(syllable):
            if is_hard(letter):
                syllable[i] = c

    c = syllables[-1][-1]
    if is_hard(c):
        i = ord(c.lower())
        a = abs(i - ord("a"))
        o = abs(i - ord("o"))
        u = abs(i - ord("u"))

        d = min(a, o, u)
        if d == a:
            syllables[-1].extend(["a", "h"])
        elif d == o:
            syllables[-1].extend(["o", "h"])
        else:
            syllables[-1].extend(["u", "h"])

    print("".join(["".join(syllable) for syllable in syllables]), end=" ")