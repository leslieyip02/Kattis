from math import pi

circle = "ABCDEFGHIJKLMNOPQRSTUVWXYZ '"
for _ in range(int(input())):
    aphorism = input()
    dist = 0
    pos = circle.index(aphorism[0])
    for letter in aphorism[1:]:
        i = circle.index(letter)
        d = abs(i - pos)
        dist += min(d, 28 - d)
        pos = i
        
    print(dist * pi / 7 + len(aphorism))