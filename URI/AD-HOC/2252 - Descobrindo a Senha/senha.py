k = 1
while True:
    try:
        N = int(input())
        vals = [[x, 0] for x in input().split()]
        for i in range(10):
            vals[i][1] = i
        vals.sort(key = lambda l: (l[0], -l[1]), reverse = True)
        senha = ""
        for i in range(N):
            senha += str(vals[i][1])
        print("Caso {}: {}".format(k, senha))
        k += 1
    except EOFError:
        break