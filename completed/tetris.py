pieces = [
    ((0, 0, 0, 0), (0,)), 
    ((0, 0),), 
    ((0, 0, 1), (1, 0)), 
    ((1, 0, 0), (0, 1)), 
    ((0, 0, 0), (0, 1), (1, 0, 1), (1, 0)),
    ((0, 0, 0), (0, 0), (0, 1, 1), (2, 0)),
    ((0, 0, 0), (0, 0), (1, 1, 0), (0, 2))
]

c, p = [int(i) for i in input().split(" ")]
field = [int(i) for i in input().split(" ")]

ways = 0
for o in pieces[p - 1]:
    for i in range(c - (len(o) - 1)):
        section = field[i:i + len(o)]

        while min(section) > 0:
            for j in range(len(section)):
                section[j] -= 1

        fit = True
        for j in range(len(o)):
            if o[j] != section[j]:
                fit = False
                break
                
        if fit:
            ways += 1
            
print(ways)