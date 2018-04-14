# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1288 - Canhão de Destruição
def knapsack(W, wg, val, n):
    if ks[n-1][W] != 0: return ks[n-1][W]
    if W == 0 or n == 0: return 0
    if wg[n-1] > W:
        result = knapsack(W, wg, val, n-1)
    else:
        result = max(
            val[n-1] + knapsack(W-wg[n-1], wg, val, n-1), knapsack(W, wg, val, n-1))
    ks[n-1][W] = result
    return result

T = int(input())
for _ in range(T):
    N = int(input())
    danos, pesos = [], []
    for _ in range(N):
        d, p = map(int, input().split())
        danos.append(d)
        pesos.append(p)
    K = int(input())
    R = int(input())
    ks = [[0 for _ in range(K+1)] for _ in range(N)]
    result = knapsack(K, pesos, danos, N)
    if result >= R:
        print("Missao completada com sucesso")
    else:
        print("Falha na missao")