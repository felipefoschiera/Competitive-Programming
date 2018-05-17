# OBI 2017 - Dividindo o Império

import sys

res = 0


def dfs(i, pai):
    global res
    peso = 1
    for p in g[i]:  # Para cada cidade p ligada a i que não é o próprio pai de i
        if p != pai:
            # O peso da cidade p é, além dela mesma(1),
            # a quant. de cidades ligada à ela em uma direção.
            peso += dfs(p, i)
    '''
    Sendo 'peso' a quant. de cidades da cidade i até o fim em um direção,
    a quant. no outro lado é N - peso.
    A diferença então é (N - peso - peso), ou seja: N - 2 * peso
    '''
    dif = abs(N - 2*peso)
    if dif < res:
        res = dif
    return peso


N = int(input())
g = [[] for _ in range(N+1)]

for i in range(1, N):
    A, B = map(int, input().split())
    g[A].append(B)
    g[B].append(A)
res = N
sys.setrecursionlimit(10**5)
dfs(1, -1)
print(res)

'''
4
1 2
2 3
3 4

g = [[], [2], [1, 3], [2, 4], [3]]
'''
