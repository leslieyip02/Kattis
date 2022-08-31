class Node:
    def __init__(self, v):
        self.v = v
        self.l = None
        self.r = None

    def insert(self, v):
        if v < self.v:
            if self.l:
                self.l.insert(v)
            else:
                self.l = Node(v)
        else:
            if self.r:
                self.r.insert(v)
            else:
                self.r = Node(v)    

n = int(input())
while n != 0:
    a = [int(i) for i in input().split(" ")]

    root = Node(a[0])
    for i in range(1, n):
        root.insert(a[i])

    root.print()

    n = int(input())