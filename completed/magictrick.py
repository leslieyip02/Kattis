word = input()
print(1 if len(list(word)) == len(set(word)) else 0)