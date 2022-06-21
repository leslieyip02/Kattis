combo = input()

while combo != "0 0 0 0":
    i, x, y, z = [int(a) for a in combo.split(" ")]

    # minimum 3 full turns
    sum = 1080

    # 1st spin
    sum = sum + ((i - x) * 9 if i >= x else 360 - (x - i) * 9)

    # 2nd spin
    sum = sum + ((y - x) * 9 if y >= x else 360 - (x - y) * 9)

    # 3rd spin
    sum = sum + ((y - z) * 9 if y >= z else 360 - (z - y) * 9)

    print(sum)

    combo = input()
    