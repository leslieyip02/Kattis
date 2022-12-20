magic_code_lengths = [ 1, 3, 3, 5, 5, 5, 7, 7, 7, 7, 7, 
    9, 9, 9, 9, 9, 9, 9, 9, 11, 11, 11, 11, 11, 11, 11 ]

s = [i.lower() for i in input() if i.isalpha()]
alphabets = dict((c, s.count(c)) for c in set(s) if c.isalpha())
order = sorted(alphabets, key=alphabets.get, reverse=True)

length = 3 * (len(s) - 1)
for c in order:
    length += alphabets[c] * magic_code_lengths.pop(0)

print(length)