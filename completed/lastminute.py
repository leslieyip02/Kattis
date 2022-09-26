au, bu, ar, br = [int(i) for i in input().split(' ')]
c = au * min(br, 1) + bu * min(ar, 1) + ar * br
print(c if c > 0 else min(au, bu))