txt = input()

n = 0
for i in range(int(len(txt) / 3)):
    seg = txt[i * 3 : (i + 1) * 3]
    
    if seg[0] != 'P':
        n = n + 1

    if seg[1] != 'E':
        n = n + 1

    if seg[2] != 'R':
        n = n + 1

print(n)