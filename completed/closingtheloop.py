n = int(input())
for i in range(1, n + 1):
    pieces = { "B": [], "R": [] }
    
    _ = input()
    for piece in input().split(" "):
        color = piece[-1]
        pieces[color].append(int(piece[:-1]))

    if len(pieces["B"]) == 0 or len(pieces["R"]) == 0:
        print(f"Case #{i}: 0")
        continue

    pieces["B"] = sorted(pieces["B"])[::-1]
    pieces["R"] = sorted(pieces["R"])[::-1]

    length = 0
    for j in range(min(len(pieces["B"]), len(pieces["R"]))):
        length += pieces["B"][j] - 1
        length += pieces["R"][j] - 1

    print(f"Case #{i}: {length}")