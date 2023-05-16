def smallest(b):
    if len(b) == 1:
        return b

    s = ""
    b = [d for d in b]

    n = ['C', 'L', 'X', 'V', 'I']
    for i in range(len(n) - 1):
        if n[i] in b:
            if i % 2 == 0:
                if n[i + 1] not in b and b.count(n[i + 2]) == 1:
                    s += n[i] * (b.count(n[i]) - 1)
                    s += n[i + 2] + n[i]
                    b.remove(n[i + 2])
                else:
                    s += n[i] * b.count(n[i])
            else:
                if b.count(n[i + 1]) == 1 or \
                        (b.count(n[i + 1]) == 2 and i + 3 < len(n) and
                         n[i + 2] not in b and b.count(n[i + 3]) == 1):
                    s += n[i] * (b.count(n[i]) - 1)
                    s += n[i + 1] + n[i]
                    b.remove(n[i + 1])
                else:
                    s += n[i] * b.count(n[i])

    return s + 'I' * b.count('I')


print(smallest(input()))


# t = ["I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
#      "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX",
#      "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX",
#      "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL",
#      "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L",
#      "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX",
#      "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX",
#      "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX",
#      "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC",
#      "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"]

# for i in t:
#     print(i, smallest(i))
