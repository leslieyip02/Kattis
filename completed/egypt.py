ln = sorted(int(i) for i in input().split(' ')) 
while not all(i == 0 for i in ln): 
    a, b, c = ln 
    print("right" if a * a + b * b == c * c else "wrong") 

    ln = sorted(int(i) for i in input().split(' '))
