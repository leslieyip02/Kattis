t = int(input())
for _ in range(t):
    sounds = input().split(' ')
    known = set()

    ln = input()
    while ln != "what does the fox say?":
        _, _, sound = ln.split(' ')
        known.add(sound)
        ln = input()

    fox = []
    for sound in sounds:
        if sound not in known:
            fox.append(sound)

    print(' '.join(fox))