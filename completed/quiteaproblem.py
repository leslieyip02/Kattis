import sys

for ln in sys.stdin:
    print("yes" if "problem" in ln.lower() else "no")