import sys
sys.setrecursionlimit(50000)

class Friend:
    def __init__(self, debt):
        self.debt    = debt
        self.grouped = False
        self.friends = []

def pool(friend):
    friend.grouped = True
    debt = 0
    for i in friend.friends:
        if not clique[i].grouped:
            debt = debt + pool(clique[i])

    return debt + friend.debt

def main():
    global clique
    clique = []

    n, m = [int(i) for i in input().strip().split(" ")]
    for _ in range(n):
        friend = Friend(int(input()))
        clique.append(friend)

    for _ in range(m):
        a, b = [int(i) for i in input().strip().split(" ")]
        clique[a].friends.append(b)
        clique[b].friends.append(a)

    for friend in clique:
        if not friend.grouped:
            if pool(friend) != 0:
                print("IMPOSSIBLE")
                return

    print("POSSIBLE")

if __name__ == "__main__":
    main()