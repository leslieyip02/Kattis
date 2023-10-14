card_power = {
    "shadow": 6,
    "gale": 5,
    "ranger": 4,
    "anvil": 7,
    "vexia": 3,
    "guardian": 8,
    "thunderheart": 6,
    "frostwhisper": 2,
    "voidclaw": 3,
    "ironwood": 3,
    "zenith": 4,
    "seraphina": 1
}

def calculate_power(cards, location):
    power = 0
    for card in cards:
        power += card_power[card]

        if card == "thunderheart" and len(cards) == 4:
            power += card_power[card]
        if card == "zenith" and location == 1:
            power += 5
        if card == "seraphina":
            power += len(cards) - 1

    return power

wins = [0, 0]
total_power = [0, 0]
for location in range(3):
    cards_1 = [card.lower() for card in input().split()[1:]]
    cards_2 = [card.lower() for card in input().split()[1:]]

    power_1 = calculate_power(cards_1, location)
    total_power[0] += power_1
    power_2 = calculate_power(cards_2, location)
    total_power[1] += power_2

    if power_1 > power_2:
        wins[0] += 1
    elif power_1 < power_2:
        wins[1] += 1

if wins[0] > wins[1]:
    result = "Player 1"
elif wins[0] < wins[1]:
    result = "Player 2"
else:
    if total_power[0] > total_power[1]:
        result = "Player 1"
    elif total_power[0] < total_power[1]:
        result = "Player 2"
    else:
        result = "Tie"
print(result)
