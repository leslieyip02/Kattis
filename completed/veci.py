from itertools import permutations

x = input()
digits = [i for i in x]

nums = sorted(set([int("".join(d)) for d in permutations(digits)]))

try:
    print(nums[nums.index(int(x)) + 1])
except:
    print(0)
