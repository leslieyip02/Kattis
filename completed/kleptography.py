key = "abcdefghijklmnopqrstuvwxyz"

n, m = [int(i) for i in input().split(' ')]
seen, encrypted = input(), input()

decrypted = [i for i in seen.zfill(m)]
for i in range(m - 1, n - 1, -1): 
    decrypted[i - n] = key[(key.index(encrypted[i]) - key.index(decrypted[i]) + 26) % 26]

print(''.join(decrypted))