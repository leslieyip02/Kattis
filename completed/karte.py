c = {
    'P': [],
    'K': [],
    'H': [],
    'T': []
}

s = input()
for i in range(int(len(s) / 3)):
    n = int(s[i * 3 + 1 : i * 3 + 3])
    if n in c[s[i * 3]]:
        print("GRESKA")
        quit()
    c[s[i * 3]].append(n)

print(f"{13 - len(c['P'])} {13 - len(c['K'])} {13 - len(c['H'])} {13 - len(c['T'])}")
    