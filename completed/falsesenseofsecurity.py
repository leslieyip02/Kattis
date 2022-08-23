m = {
    "A": ".-",
    "B": "-...",
    "C": "-.-.",
    "D": "-..",
    "E": ".",
    "F": "..-.",
    "G": "--.",
    "H": "....",
    "I": "..",
    "J": ".---",
    "K": "-.-",
    "L": ".-..",
    "M": "--",
    "N": "-.",
    "O": "---",
    "P": ".--.",
    "Q": "--.-",
    "R": ".-.",
    "S": "...",
    "T": "-",
    "U": "..-",
    "V": "...-",
    "W": ".--",
    "X": "-..-",
    "Y": "-.--",
    "Z": "--..",
    "_": "..--",
    ".": "---.",
    ",": ".-.-",
    "?": "----"
}

while True:
    try:
        encoded = input()

        c = ""
        nums = []
        for e in encoded:
            c += m[e]
            nums.insert(0, len(m[e]))

        i = 0
        decoded = ""
        for n in nums:
            for l, d in m.items():
                if d == c[i:i + n]:
                    decoded += l
                    break
            i += n;

        print(decoded)

    except:
        quit()