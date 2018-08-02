# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1487 - Six Flags

def knapsack(W, wg, val, n):
    if ks[n-1][W] != 0: return ks[n-1][W]
    if W == 0 or n == 0: return 0
    if wg[n-1] > W:
        result = knapsack(W, wg, val, n-1)
    else:
        result = max(val[n-1] + knapsack(W-wg[n-1], wg, val, n), knapsack(W, wg, val, n-1))
    ks[n-1][W] = result
    return result

inst = 1
while True:
    N, T = map(int, input().split())
    if N == 0 and T == 0: break
    tempos, pontos = [], []
    for _ in range(N):
        d, p = map(int, input().split())
        tempos.append(d)
        pontos.append(p)
    ks = [[0 for _ in range(T+1)] for _ in range(N)]
    print("Instancia", inst)
    inst += 1
    print(knapsack(T, tempos, pontos, N))
    print()