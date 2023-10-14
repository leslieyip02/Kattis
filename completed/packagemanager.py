t, b = [int(i) for i in input().split()]
stores = [int(i) for i in input().split()]
latest = {}
for _ in range(t):
    product, version = input().split()
    latest[product] = int(version)

for store in stores:
    products = {}
    for entry in range(store):
        product, version = input().split()
        products[product] = products.get(product, 0)
        products[product] = max(int(version), products[product])

    steps = 0
    for product, version in products.items():
        steps += latest[product] - version
    print(steps)
