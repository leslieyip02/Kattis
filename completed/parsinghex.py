import sys
import re

for ln in sys.stdin:
    ln = ln.strip()
    for m in re.finditer("0x", ln.lower()):
        i = m.start() + 2
        while (i < len(ln) and (ln[i].isdecimal() or
            (ln[i].isalpha() and ln[i].lower() <= 'f'))):
            i += 1
            
        n = ln[m.start():i]
        print(n, int(n, 16))
