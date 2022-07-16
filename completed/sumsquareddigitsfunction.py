def ssd(b, n):
    digits = []
    while n > 0:
        digits.append(n % b)
        n = int(n / b)

    return sum([i ** 2 for i in digits])

for _ in range(int(input())):
    k, b, n = [int(i) for i in input().split(" ")]
    print(k, ssd(b, n))