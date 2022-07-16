word = [l for l in input()]
key = input()

strokes = 0
for k in key:
    try:
        word.index(k)
        word = list(filter(lambda l: l != k, word))

    except:
        strokes += 1
        if strokes >= 10:
            print("LOSE")
            quit()

    if len(word) == 0:
        print("WIN")
        quit()