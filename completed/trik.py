cups = [1, 0, 0]

swaps = {
    'A': (0, 1),
    'B': (1, 2),
    'C': (0, 2)
}

def swap(a, b):
    tmp = cups[a]
    cups[a] = cups[b]
    cups[b] = tmp

def main():
    orders = input()
    for order in orders:
        swap(*swaps[order])

    print(cups.index(1) + 1)

if __name__ == "__main__":
    main()