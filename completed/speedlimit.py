n = int(input())
while n != -1:
    et = 0
    d = 0
    for _ in range(n):
        s, t = [int(i) for i in input().split(" ")]
        d += s * (t - et)
        et = t
    print(f"{d} miles")
    
    n = int(input())