t = input()

a = ":)" in t
b = ":(" in t

if a and b:
    print("double agent")
elif a:
    print("alive")
elif b:
    print("undead")
else:
    print("machine")