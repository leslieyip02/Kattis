import sys
import math

for ln in sys.stdin:
    p = int(ln)

    s = 0
    for d in range(1, int(math.sqrt(p)) + 1):
        if p % d == 0:
            s += d
            
            f = p // d
            if d != f and f != p:
                s += f
    
    if s == p:
        print(f"{p} perfect")
    elif abs(p - s) <= 2:
        print(f"{p} almost perfect")
    else:
        print(f"{p} not perfect")