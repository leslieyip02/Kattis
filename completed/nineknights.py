b = []
d = [(1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1), (-2, 1), (-1, 2)]
def jump(x1, y1):
    for o in d:
        x2 = x1 + o[0]
        y2 = y1 + o[1]
        
        if 0 <= x2 < 5 and 0 <= y2 < 5:
            if b[y2][x2] == 'k':
                return False

    return True

for _ in range(5):
    b.append(input())

c = 0
for y in range(5):
    for x in range(5):
        if b[y][x] == 'k':
            c += 1
            if not jump(x, y):
                print("invalid")
                quit()

print("valid" if c == 9 else "invalid")
    