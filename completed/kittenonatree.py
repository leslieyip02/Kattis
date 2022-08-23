parents = {}
k = input()
while True:
    branch = [i for i  in input().split(" ")]
    if branch == ["-1"]:
        break

    for leaf in branch[1:]:
        parents[leaf] = branch[0]

print(k, end=" ")
while k in parents:
    k = parents[k]
    print(k, end=" ")