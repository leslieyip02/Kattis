n, b = [i for i in input().strip().split(" ")]

values = {
    "A": (11, 11),
    "K": (4 , 4 ),
    "Q": (3 , 3 ), 
    "J": (20, 2 ),
    "T": (10, 10),
    "9": (14, 0 ),
    "8": (0 , 0 ),
    "7": (0 , 0 )
}

sum = 0
for _ in range(int(n) * 4):
    card = input().strip()
    num, suit = card[0], card[1]

    sum = sum + values[num][0 if suit == b else 1]

print(sum)