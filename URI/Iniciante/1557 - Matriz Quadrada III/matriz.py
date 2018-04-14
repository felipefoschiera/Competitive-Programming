# -*- coding: utf-8 -*-

while True:
    N = int(input())
    if N == 0:
        break
    matriz = [[0 for i in range(N)] for i in range(N)]
    max_num = 0
    for i in range(N):
        for j in range(N):
            n = 2 ** (j + i)
            matriz[i][j] = n
            if n > max_num:
                max_num = n
    just = len(str(max_num))
    
    for i in range(N):
        for j in range(N):
            while len(str(matriz[i][j])) != just:
                matriz[i][j] = " " + str(matriz[i][j])
            if j != N - 1:
                print(matriz[i][j], end = " ")
            else:
                print(matriz[i][j])
    print()