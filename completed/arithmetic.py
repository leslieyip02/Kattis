# convert to binary
# 1 group of 3 bits represents 8 values (0 to 7)
# 1 group of 4 bits represents 16 values (0 to F)

base8 = {
    '0': "000",
    '1': "001",
    '2': "010",
    '3': "011",
    '4': "100",
    '5': "101",
    '6': "110",
    '7': "111"
}

base16 = {
    "0000": '0',
    "0001": '1',
    "0010": '2',
    "0011": '3',
    "0100": '4',
    "0101": '5',
    "0110": '6',
    "0111": '7',
    "1000": '8',
    "1001": '9',
    "1010": 'A',
    "1011": 'B',
    "1100": 'C',
    "1101": 'D',
    "1110": 'E',
    "1111": 'F',
}

n = input()
bits = "0" * (len(n) % 4)

m = ""
for d in n:
    bits = bits + base8[d]

    if len(bits) % 4 == 0:
        for i in range(0, len(bits), 4):
            m = m + base16[bits[i:i + 4]]
        bits = ""

m = m.lstrip('0')
if len(m) == 0:
    m = '0'

print(m)

# print(hex(int(n, 8)))