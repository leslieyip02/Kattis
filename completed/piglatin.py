import sys

for ln in sys.stdin:
    s = []
    for w in ln.strip().split(' '):
        if w[0] in "aeiouy":
            s.append(w + "yay")
        else:
            i = 1
            while w[i] not in "aeiouy":
                i += 1
            s.append(w[i:] + w[:i] + "ay")
    print(' '.join(s))