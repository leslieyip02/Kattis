# for each ring, there are (i - 1) * 6 rings
# for odd rings, there are 2 ways in, 2 ways out and 2 ways along
# for even rings, there is 1 way in, 3 ways out and 2 ways along

# max ring depth for i that can trace back to start is floor(i / 2)

for _ in range(int(input())):
    # ways to reach the i-th ring with the current number of moves
    ways_to_reach = [6, 12, 6]

