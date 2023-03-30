pair = { "(": ")", "[": "]", "{": "}" }
open = ["(", "[", "{"]

n = input()
seq = input()
stack = []

valid = True
for b in seq:
    if b in open:
        stack.append(b)
    else:
        if len(stack) == 0 or b != pair[stack.pop()]:
            valid = False
            break

print("Valid" if valid and len(stack) == 0 else "Invalid")