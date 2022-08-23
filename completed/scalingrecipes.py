t = int(input())
for i in range(1, t + 1):
    print(f"Recipe # {i}")

    r, p, d = [int(i) for i in input().split(" ")]
    
    f = d / p
    ingredients = []
    for _ in range(r):
        name, weight, percentage = [i for i in input().split(" ")]
        if float(percentage) == 100:
            f *= float(weight)
        ingredients.append((name, float(percentage)))

    for ingredient in ingredients:
        print(ingredient[0], ingredient[1] * f * 0.01)

    print("----------------------------------------")