notes = ["A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"]
played = set()

_ = input()
for note in input().split(" "):
    if len(note) > 0:
        played.add(note)

keys = []
intervals = [2, 2, 1, 2, 2, 2]
for i in range(12):
    note = notes[i]
    scale = [note]

    j = i
    for interval in intervals:
        j = (j + interval) % 12
        scale.append(notes[j])

    inKey = True
    for p in played:
        if p not in scale:
            inKey = False
            break

    if inKey:
        keys.append(note)

print("none" if len(keys) == 0 else " ".join(keys))
