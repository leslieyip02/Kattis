y, p = input().split(" ")

if y[-1] == 'e':
    print(y + 'x' + p)
elif (y[-1] == 'a' or y[-1] == 'i' or
    y[-1] == 'o' or y[-1] == 'u'):
    print(y[:-1] + 'ex' + p)
elif y[-2:] == 'ex':
    print(y + p)
else:
    print(y + "ex" + p)