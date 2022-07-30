s, n = [int(i) for i in input().split(" ")]
hands = [[i, 0] for i in range(1, n + 1)]

i = 0
while len(hands) > 1:
    i = (i + s - 1) % len(hands)

    if hands[i][1] == 0:
        hands[i][1] = 1
        hands.insert(i, [hands[i][0], 1])
    elif hands[i][1] == 1:
        hands[i][1] = 2
        i += 1
    else:
        hands.pop(i)

print(hands[0][0])