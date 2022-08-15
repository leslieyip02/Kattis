l = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."

ln = input()
while ln != "0":
    encrypted = ""
    r, w = ln.split(" ")
    for c in w:
        i = (l.index(c) + int(r)) % 28
        encrypted = l[i] + encrypted
    print(encrypted)

    ln = input()