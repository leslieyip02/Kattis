from random import randint, shuffle

n = int(input())
dishes = []

for _ in range(n):
    menu = [i for i in input().split(' ')]
    dishes.append(menu[1:])

recommendation = dishes[randint(0, n - 1)]
shuffle(recommendation)
m = len(recommendation)

print(m)
for dish in recommendation:
    print(dish)