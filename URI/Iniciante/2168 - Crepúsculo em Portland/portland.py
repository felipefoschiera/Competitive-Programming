# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2168 - Crepúsculo em Portland
N = int(input())
matriz = [[0 for _ in range(N+1)] for _ in range(N+1)]
for i in range(N+1):
    linha = list(map(int, input().split()))
    for j in range(N+1):
        matriz[i][j] = linha[j]
for i in range(N):
    res = ""
    for j in range(N):
        res += ("U" if matriz[i][j] + matriz[i][j+1] + matriz[i+1][j] + matriz[i+1][j+1] < 2 else "S")
    print(res)