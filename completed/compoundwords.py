from itertools import permutations

subs = []
words = set()
while True:
    try:
        subs.extend(input().split(" "))
    except:
        subs = list(filter(lambda x: len(x) > 0, subs))
        for pair in permutations(subs, 2):
            words.add("".join(pair))
        
        for word in sorted(words):
            print(word)

        quit()