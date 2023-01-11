headers = input()
attrs = dict((attr, i) for i, attr in enumerate(headers.split(" ")))

songs = []
m = int(input())
for _ in range(m):
    songs.append(input().split(" "))

n = int(input())
for _ in range(n):
    sort_attr = input()
    sort_attr_index = attrs[sort_attr]
    songs = sorted(songs, key=lambda song: song[sort_attr_index])

    print(headers)
    for song in songs:
        print(" ".join(song))
    print()