from string import ascii_lowercase
from random import choice, choices, randint

words = set()

a, b = [int(i) for i in input().split(' ')]
c = b // 2 + 1
while len(words) < c:
    word = ''.join(choices(ascii_lowercase, k=randint(1, 15)))
    words.add(word)

words = list(words)
essay = words + list(choices(words, k=randint(a - c, b - c)))
print(' '.join(essay))
