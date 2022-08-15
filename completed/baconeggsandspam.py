n = int(input())
while n != 0:
    foods = {}

    for _ in range(n):
        order = input().split(" ")
        name = order.pop(0)

        for item in order:
            foods[item] = foods.get(item, [])
            foods[item].append(name)

    ordered = sorted(foods.keys())
    for food in ordered:
        print(f"{food} {' '.join(sorted(foods[food]))}")
    print()

    n = int(input())