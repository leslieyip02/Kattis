n, m = [bin(int(i))[2:] for i in input().split(' ')]

t = 0
for b in m:
    if b == '1':
        t += 1

print(t)

# n, m = [int(i) for i in input().split(' ')]

# t = 0
# # count the number of set bits
# while m > 0:
#     # check if the bit at 1 is set
#     t += m & 1
#     # right shift to get the next bit
#     m >>= 1

# print(t)