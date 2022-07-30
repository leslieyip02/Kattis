for _ in range(int(input())):
    n = int(input())
    q = input()

    grps = {}
    for i in range(n):
        grps[q[i]] = grps.get(q[i], 0) + 1

    t = 0
    current = 0
    done = {}
    for i in range(n - 1, -1, -1):
        if not done.get(q[i], False):
            t += (current - (n - 1 - i)) * grps[q[i]]
            current += grps[q[i]]
            done[q[i]] = True

    print(t * 5)