# https://codereview.stackexchange.com/questions/269223/counting-swaps-in-a-sequence-sorting-algorithm

s = input()

inversions = 0
ones = 0
strings = 1
m = 1000000007

for b in s:
    if b == '0':
        inversions += ones
        inversions %= m
    
    elif b == '1':
        ones += strings
        ones %= m

    else:
        inversions += inversions + ones
        ones += ones + strings
        strings *= 2

        inversions %= m
        ones %= m
        strings %= m

print(inversions)
