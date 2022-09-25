import sys

d = v = 0
h0 = m0 = s0 = 0
for ln in sys.stdin:
    ln = ln.split(' ')

    h1, m1, s1 = [int(i) for i in ln[0].split(':')]
    t = (h1 - h0) * 3600 + (m1 - m0) * 60 + (s1 - s0)
    d += t * v
    
    if len(ln) > 1:
        v = int(ln[1]) / 3600    
    else:
        print(f"{ln[0][:-1]} {d:.2f} km")

    h0, m0, s0 = h1, m1, s1
