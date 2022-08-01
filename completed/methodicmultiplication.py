x = input().count("S")
y = input().count("S")

p = "0"
for i in range(x * y):
    p = "S(" + p + ")"
print(p)