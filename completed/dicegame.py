g = sum([int(i) for i in input().split(" ")])
e = sum([int(i) for i in input().split(" ")])

print("Tie" if g == e else ("Gunnar" if g > e else "Emma"))
