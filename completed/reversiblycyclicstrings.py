s = input()
print(1 if ''.join(reversed(s)) in s * 2 else 0)