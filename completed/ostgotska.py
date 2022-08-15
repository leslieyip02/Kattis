words = [i for i in input().split(" ")]

c = 0
for word in words:
    try:
        if word.index("ae") >= 0:
            c += 1
    except:
        continue

print("dae ae ju traeligt va" if c / len(words) >= 0.4 else "haer talar vi rikssvenska")