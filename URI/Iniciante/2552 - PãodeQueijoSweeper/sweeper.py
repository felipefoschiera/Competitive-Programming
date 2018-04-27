# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2552 - PãodeQueijoSweeper
while True:
    try:
        N, M = map(int, input().split())
        matriz = [[0 for _ in range(M+2)] for _ in range(N+2)]
        for i in range(1, N+1):
            linha = list(map(int, input().split()))
            for j in range(1, M+1):
                matriz[i][j] = linha[j-1]
        for i in range(1, N+1):
            linha = ""
            for j in range(1, M+1):
                if matriz[i][j] == 1: linha += str(9)
                else:
                    cnt = 0
                    if matriz[i-1][j] == 1: cnt += 1
                    if matriz[i+1][j] == 1: cnt += 1
                    if matriz[i][j-1] == 1: cnt += 1
                    if matriz[i][j+1] == 1: cnt += 1
                    linha += str(cnt)
            print(linha)    
    except EOFError: break
