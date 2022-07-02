g, s, c = [int(i) for i in input().split(" ")]
buyPow = g * 3 + s * 2 + c * 1

if buyPow >= 8:
    print("Province or ", end="")
elif buyPow >= 5:
    print("Duchy or ", end="")
elif buyPow >= 2:
    print("Estate or ", end="")

if buyPow >= 6:
    print("Gold")
elif buyPow >= 3:
    print("Silver")
else:
    print("Copper")