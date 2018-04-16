# -*_ coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1624 - Promoção

def knapsack(W, wg, val, n):
    if ks[n-1][W] != 0: return ks[n-1][W]
    if W == 0 or n == 0: return 0
    if wg[n-1] > W:
        result = knapsack(W, wg, val, n-1)
    else:
        result = max(val[n-1] + knapsack(W-wg[n-1], wg, val, n-1), knapsack(W, wg, val, n-1))
    ks[n-1][W] = result
    return result

while True:
    N = int(input())
    if N == 0: break
    precos, pesos = [], []
    for _ in range(N):
        p1, p2 = map(int, input().split())
        precos.append(p1)
        pesos.append(p2)
    M = int(input())
    ks = [[0 for _ in range(M+1)] for _ in range(N+1)]
    print(knapsack(M, pesos, precos, N))