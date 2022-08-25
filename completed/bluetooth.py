left = True
right = True
mouth = { "left": [i for i in range(-8, 9)], "right": [i for i in range(-8, 9)] }

n = int(input())
for _ in range(n):
    t, c = [i for i in input().split(" ")]
    s = "left" if not t[0].isnumeric() else "right"
    
    if c == 'b':
        if s == "left":
            left = False
        else:
            right = False
    else:
        if s == "left":
            i = mouth[s].index(int(t))
        else:
            i = mouth[s].index(int(t[1] + t[0]))
        mouth[s].pop(i)

if left or right:
    s = "left" if left else "right"
    teeth = mouth[s]
    if teeth[0] < 0 and teeth[-1] > 0:
        print(0 if left else 1)
    else:
        print(2)
else:
    print(2)
