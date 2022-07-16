unis = []

for _ in range(int(input())):
    if len(unis) >= 12:
        break
        
    uni, team = input().split(" ")
    try:
        unis.index(uni)
    except:
        print(uni, team)
        unis.append(uni)