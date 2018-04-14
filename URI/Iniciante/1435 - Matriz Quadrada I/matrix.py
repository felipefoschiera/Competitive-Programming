while True:
    try:
        N = int(input())
        if N == 0:
            break
        for linha in range(1, N + 1):
            for coluna in range(1, N + 1):
                minimo = linha
                if coluna < minimo:
                    minimo = coluna
                if N - linha + 1 < minimo:
                    minimo = N - linha + 1
                if N - coluna + 1 < minimo:
                    minimo = N - coluna + 1
                if coluna != N:
                    print("%3d" % minimo, end = ' ')
                else:
                    print("%3d" % minimo)
        print()
    except: 
        breakwhile True:
    try:
        N = int(input())
        if N == 0:
            break
        for linha in range(1, N + 1):
            for coluna in range(1, N + 1):
                minimo = linha
                if coluna < minimo:
                    minimo = coluna
                if N - linha + 1 < minimo:
                    minimo = N - linha + 1
                if N - coluna + 1 < minimo:
                    minimo = N - coluna + 1
                if coluna != N:
                    print("%3d" % minimo, end = ' ')
                else:
                    print("%3d" % minimo)
        print()
    except: 
        break