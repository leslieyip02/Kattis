n = int(input())
while n != 0:
    am = []
    pm = []

    for _ in range(n):
        t = input().split(' ')

        if t[1] == "a.m.":
            am.append(t[0].split(':'))
        else:
            pm.append(t[0].split(':'))

    for t in sorted(am, key=lambda x: (int(x[0]) % 12, x[1])):
        print(f"{':'.join(t)} a.m.")

    for t in sorted(pm, key=lambda x: (int(x[0]) % 12, x[1])):
        print(f"{':'.join(t)} p.m.")

    print()
    n = int(input())