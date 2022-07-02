cards = [i[0] for i in input().split(" ")]
print(max([cards.count(i) for i in cards]))