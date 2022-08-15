moves = [(1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1), (-2, 1), (-1, 2)]

def jump(x, y, m):
    if m < board[y][x]:
        board[y][x] = m
    else:
        return

    for move in moves:
        ox, oy = move
        if 0 <= x + ox < 8 and 0 <= y + oy < 8:
            jump(x + move[0], y + move[1], m + 1)    

def main():
    for _ in range(int(input())):
        global board
        board = [[100 for _ in range(8)] for _ in range(8)]

        p0 = input()
        x = ord(p0[0]) - 97
        y = int(p0[1]) - 1
        jump(x, y, 0)

        f = [(x, y)]
        for j in range(8):
            for i in range(8):
                if board[j][i] > board[f[0][1]][f[0][0]]:
                    f = [(i, j)]
                elif board[j][i] == board[f[0][1]][f[0][0]]:
                    f.append((i, j))

        p = [chr(p[0] + 97) + str(p[1] + 1) for p in f]
        p = sorted(p, key=lambda x: x[1], reverse=True)

        print(f"{board[f[0][1]][f[0][0]]} {' '.join(p)}")

if __name__ == "__main__":
    main()