# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2436 - Robô
L, C = map(int, input().split())
a, b = map(int, input().split())
matriz = [[0 for _ in range(C+2)] for _ in range(L+2)]

for i in range(1, L+1):
    linha = input().split()
    for j in range(1, C+1):
        matriz[i][j] = linha[j-1]

while True:
    matriz[a][b] = 0
    if matriz[a+1][b] == '1':
        a += 1
    elif matriz[a-1][b] == '1':
        a -= 1
    elif matriz[a][b+1] == '1':
        b += 1
    elif matriz[a][b-1] == '1':
        b -= 1
    else:
        break
print(a, b)