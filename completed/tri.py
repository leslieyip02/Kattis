a, b, c = [int(i) for i in input().split(" ")]

if a + b == c:
    print(f"{a}+{b}={c}")
elif a - b == c:
    print(f"{a}-{b}={c}")
elif a * b == c:
    print(f"{a}*{b}={c}")
elif a / b == c:
    print(f"{a}/{b}={c}")
elif b + c == a:
    print(f"{a}={b}+{c}")
elif b - c == a:
    print(f"{a}={b}-{c}")
elif b * c == a:
    print(f"{a}={b}*{c}")
elif b / c == a:
    print(f"{a}={b}/{c}")