from math import floor


def main():
    t = int(input())
    for i in range(1, t + 1):
        [alien_num, src_lang, target_lang] = input().split(" ")
        
        # split number into digits
        alien_digits = [digit for digit in alien_num]

        # index position corresponds to value
        src_digits = [digit for digit in src_lang]
        src_base = len(src_lang)

        target_digits = [digit for digit in target_lang]
        target_base = len(target_lang)

        # find base 10 value of number
        value = 0
        num_digits = len(alien_num)
        for k, digit in enumerate(alien_digits):
            value = value + src_digits.index(digit) * src_base ** (num_digits - k - 1)

        # find number of digits of translated number
        num_digits = 1
        tmp = value
        while tmp >= target_base:
            tmp /= target_base
            num_digits = num_digits + 1

        # add in the target digit for each place
        translated_num = ""
        for k in range(num_digits - 1, -1, -1):
            # find index of digit at the i-th position
            index = floor(value / (target_base ** k))
            translated_num = translated_num + target_digits[index]
            
            value = value - (target_base ** k) * index
            
        print(f"Case #{i}: {translated_num}")

    return

if __name__ == '__main__':
    main()