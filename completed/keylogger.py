keys = {
    "clank": "A",
    "bong": "B",
    "click": "C",
    "tap": "D",
    "poing": "E",
    "clonk": "F",
    "clack": "G",
    "ping": "H",
    "tip": "I",
    "cloing": "J",
    "tic": "K",
    "cling": "L",
    "bing": "M",
    "pong": "N",
    "clang": "O",
    "pang": "P",
    "clong": "Q",
    "tac": "R",
    "boing": "S",
    "boink": "T",
    "cloink": "U",
    "rattle": "V",
    "clock": "W",
    "toc": "X",
    "clink": "Y",
    "tuc": "Z",
    "whack": " "
}

caps = False
str = ""
for _ in range(int(input())):
    sound = input()

    if sound == "pop":
        str = str[:-1]
    else:
        if (sound == "bump" or 
            sound == "dink" or 
            sound == "thumb"):
            caps = False if caps else True

        elif caps:
             str+= keys[sound]
        else:
             str += keys[sound].lower()

print(str)