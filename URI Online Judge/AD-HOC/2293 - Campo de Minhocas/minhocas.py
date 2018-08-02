# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2293 - Campo de Minhocas
def coluna(matriz, i):
    return [row[i] for row in matriz]
n, m = map(int, input().split())
matriz = [[0 for _ in range(m)] for _ in range(n)]

for i in range(n):
    nums = list(map(int, input().split()))
    for j in range(m):
        matriz[i][j] = nums[j]

maior_soma = 0
for i in range(n):
    soma = sum(matriz[i])
    maior_soma = max(maior_soma, soma)
for j in range(m):
    soma_coluna = sum(coluna(matriz, j))
    maior_soma = max(maior_soma, soma_coluna)
print(maior_soma)