words = [i for i in input().split(" ")]
for word in words:
    if words.count(word) > 1:
        print("no")
        quit()
print("yes")