import sys

small = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tens = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

for line in sys.stdin:
    t = line.strip().split(' ')

    for i in range(len(t)):
        try:
            n = int(t[i])

            if n < 20:
                t[i] = small[n]
            else:
                t[i] = tens[n // 10 - 2] + ("" if n % 10 == 0 else "-" + small[int(t[i][1])])

            if i == 0:
                t[i] = t[i].capitalize()

        except:
            continue

    print(' '.join(t))