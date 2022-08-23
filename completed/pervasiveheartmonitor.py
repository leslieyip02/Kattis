while True:
    try:
        ln = input().split(" ")
        
        name = ""
        sum = 0
        cnt = 0
        for t in ln:
            try:
                sum += float(t)
                cnt += 1
            except:
                name += str(t) + " "
                
        print(f"{sum / cnt} {name}")
        
    except:
        quit()