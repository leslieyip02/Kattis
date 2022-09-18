ln = input()

while ln != '0':
    students = {}
    projects = {}

    while ln != '1':
        if ln.isupper():
            p = ln
            projects[p] = 0
    
        elif ln in students and (students[ln] != p or students[ln] == -1):
            students[ln] = -1

        else:
            students[ln] = p
        
        ln = input()

    for s, p in students.items():
        if p == -1:
            continue

        projects[p] += 1
        
    projects = { p: projects[p] for p in sorted(projects) }
    for p in sorted(projects, key=projects.get, reverse=True):
        print(f"{p} {projects[p]}")

    ln = input()