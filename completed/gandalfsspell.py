c = [i for i in input()]
w = [i for i in input().split(' ')]

if len(c) != len(w):
    print("False")
    quit()

x = {}
y = {}
for i, j in zip(c, w):
    if x.get(i, j) != j or y.get(j, i) != i:
        print("False")
        quit()
        
    x[i] = j
    y[j] = i

print("True")