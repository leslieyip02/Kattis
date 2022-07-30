for _ in range(int(input())):
    seq = [int(i) for i in input().split(" ")]
    seq[0] = seq[1] - 1
    for i in range(1, len(seq) - 2):
        if seq[i] + 1 != seq[i + 1] and seq[i] - 1 == seq[i - 1]:
            print(i + 1)
            break