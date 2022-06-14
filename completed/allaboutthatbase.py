symbols = "123456789abcdefghijklmnopqrstuvwxyz0"

def main():
    n = int(input())
    for i in range(n):
        [x, op, y, _, z] = input().split(" ")

        valid = ""
        
        # check base 1 separately as edge case
        base1 = True
        for ch in (x + y + z):
            if ch != "1":
                base1 = False
        if base1:
            vals = [len(i) for i in [x, y, z]]
            within_range = True
            for val in vals:
                if val < 1 or val > 2 ** 32 - 1:
                    within_range = False
                    break

            if within_range:
                if ((op == "+" and vals[0] + vals[1] == vals[2]) 
                    or (op == "-" and vals[0] - vals[1] == vals[2])
                    or (op == "*" and vals[0] * vals[1] == vals[2])
                    or (op == "/" and vals[0] / vals[1] == vals[2])):

                    # print("1", vals)
                    valid = valid + "1"

        for b in range(1, 37):
            try:
                vals = [int(i, b) for i in [x, y, z]]
                within_range = True
                for val in vals:
                    if val < 1 or val > 2 ** 32 - 1:
                        within_range = False
                        break
  
                if within_range:
                    if ((op == "+" and vals[0] + vals[1] == vals[2]) 
                        or (op == "-" and vals[0] - vals[1] == vals[2])
                        or (op == "*" and vals[0] * vals[1] == vals[2])
                        or (op == "/" and vals[0] / vals[1] == vals[2])):

                        # print(symbols[b - 1], vals)
                        valid = valid + symbols[b - 1]
            except:
                continue

        if len(valid) == 0:
            valid = "invalid"
        print(valid)

    return

if __name__ == "__main__":
    main()

