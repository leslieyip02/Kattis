# base cases:
# 1 -> A
# 2 ->  B
# 3 -> B
# 4 -> A
# 5 -> A
# 6 -> B
# 7 -> B
# 8 -> B
# 9 -> A
# 10 -> A
# 11 -> A
# 12 -> B

n = int(input())

x = 1
y = 1
a = True

for i in range(n - 1):
    x -= 1
    
    if x == 0:
        if a:
            a = False
            y += 1
        else:
            a = True
            
        x = y
        
print("YES" if a else "NO")