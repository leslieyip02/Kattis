l, x = [int(i) for i in input().split(" ")]

ppl = 0
cnt = 0
for _ in range(x):
    move, g = [i for i in input().split(" ")]
    g = int(g)
    if move == "enter":
        if ppl + g > l:
            cnt += 1
        else:
            ppl += g
    else:
        ppl -= g

print(cnt)
        