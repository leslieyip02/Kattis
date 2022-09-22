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