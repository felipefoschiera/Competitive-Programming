# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2026 - Àrvore de Natal

def knapsack(W, wg, val, n):
    if ks[n-1][W] != 0: return ks[n-1][W]
    if W == 0 or n == 0: return 0
    if wg[n-1] > W:
        result = knapsack(W, wg, val, n-1)
    else:
        result = max(val[n-1] + knapsack(W-wg[n-1], wg, val, n-1), knapsack(W, wg, val, n-1))
    ks[n-1][W] = result
    return result


G = int(input())
for i in range(G):
    P = int(input())
    W = int(input())
    pesos, vals = [], []
    for _ in range(P):
        qt, p = map(int, input().split())
        pesos.append(p)
        vals.append(qt)
    ks = [[0 for _ in range(W+1)] for _ in range(P)]
    print("Galho {}:".format(i+1))
    print("Numero total de enfeites: {}".format(knapsack(W, pesos, vals, P)))
    print()