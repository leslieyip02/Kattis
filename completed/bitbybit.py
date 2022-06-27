register = []

def CLEAR(i):
    register[31 - i] = 0

def SET(i):
    register[31 - i] = 1

def OR(i, j):
    if register[31 - i] * register[31 - j] == -1:
        register[31 - i] = 1
    else:
        register[31 - i] = register[31 - i] | register[31 - j]

def AND(i, j):
    if register[31 - i] * register[31 - j] == -1:
        register[31 - i] = -1
    else:
        register[31 - i] = register[31 - i] & register[31 - j]

def main():
    global register

    instrutions = {
        "CLEAR": CLEAR,
        "SET": SET,
        "OR": OR,
        "AND": AND
    }

    n = int(input())
    while (n != 0):
        register = [-1 for _ in range(32)]
        for _ in range(n):
            line = input().split(" ")

            if len(line) == 3:
                instruction, i, j = line
                instrutions[instruction](int(i), int(j))
            else:
                instruction, i = line
                instrutions[instruction](int(i))

        for bit in register:
            print(bit if bit != -1 else "?", end="")
        print()

        n = int(input())

if __name__ == "__main__":
    main()