h0 = int(input())
if h0 < 5:
    h0 = 5

stacked = False
while not stacked:
    for i in [-5, 0, 3]:
        if ((h0 + i) % 8) == 0:
            stacked = True
            break
            
    if not stacked:
        h0 = h0 + 1

print(h0)
