hi = 1000
lo = 1

n = (hi + lo) // 2
print(n)

response = input()
while response != "correct":
    if response == "higher":
        lo = n + 1
    else:
        hi = n - 1

    n = (hi + lo) // 2
    print(n)

    response = input()