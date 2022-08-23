n, m = [int(i) for i in input().split(" ")]
d = n - m


if d > 0:
    print(f"Dr. Chaz needs {d} more {'piece' if d == 1 else 'pieces'} of chicken!")
else:
    print(f"Dr. Chaz will have {-d} {'piece' if d == -1 else 'pieces'} of chicken left over!")