cards = {
    "T": 0,
    "C": 0,
    "G": 0
}

for card in input():
    cards[card] = cards[card] + 1
print(sum([i * i for i in cards.values()]) + min(cards.values()) * 7)
