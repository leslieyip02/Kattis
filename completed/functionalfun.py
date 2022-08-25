while True:
    try:
        domain = [i for i in input().split(" ")[:-1]]
        codomain = [i for i in input().split(" ")[:-1]]
        n = int(input())
        f = [[i for i in input().split(" -> ")] for _ in range(n)]

        function = True
        injective = True
        surjective = True

        y = set()
        for i in range(n):
            y.add(f[i][1])
            
            for j in range(n):
                if i == j:
                    continue

                if f[i][0] == f[j][0] and f[i][1] != f[j][0]:
                    function = False

                if f[i][1] == f[j][1] and f[i][0] != f[j][0]:
                    injective = False

        if len(y) != len(codomain):
            surjective = False

        if not function:
            print("not a function")
        elif injective and surjective:
            print("bijective")
        elif injective:
            print("injective")
        elif surjective:
            print("surjective")
        else:
            print("neither injective nor surjective")

    except:
        quit()