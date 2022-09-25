import sys

nums = {}

for ln in sys.stdin:
    ln = ln.strip().split(' ')

    if ln[0] == "clear":
        nums = {}
  
    elif ln[0] == "def":
        _, var, val = ln
        nums[var] = int(val)
        
    else:
        res = "unknown"
        if ln[1] in nums:
            valid = True
            sum = nums[ln[1]]
            for i in range(2, len(ln) - 1, 2):
                op, var = ln[i : i + 2]
                if var not in nums:
                    valid = False
                    break
                
                sum += nums[var] * (1 if op == '+' else -1)

            if valid:
                for num, val in nums.items():
                    if val == sum:
                        res = num
                        break
                
        print(' '.join(ln[1:] + [res]))