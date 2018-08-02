# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1767 - Saco do Papai Noel
'''
( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)
( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)
( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)
'''
def knapsack(W, wt, val, n):
    ks = [[0 for _ in range(W+1)] for _ in range(n+1)]

    for i in range(n+1):
        for w in range(W+1):
            if i == 0 or w == 0:
                ks[i][w] = 0
            elif wt[i-1] <= w:
                ks[i][w] = max(val[i-1] + ks[i-1][w - wt[i-1]], ks[i-1][w])
            else:
                ks[i][w] = ks[i-1][w]
    res = ks[n][W]
    print(res, "brinquedos")

    soma_pesos = pacotes = 0
    w = W
    for i in range(n, 0, -1):
        if res <= 0: break
        if res == ks[i-1][w]:
            continue
        else:
            soma_pesos += wt[i-1]
            pacotes += 1
            res -= val[i-1]
            w -= wt[i-1]
    print("Peso: {} kg".format(soma_pesos))
    print("sobra(m) {} pacote(s)".format(n - pacotes))
    print()

N = int(input())
for _ in range(N):
    pac = int(input())
    pesos, vals = [], []
    for _ in range(pac):
        qt, p = map(int, input().split())
        vals.append(qt)
        pesos.append(p)
    W = 50
    knapsack(W, pesos, vals, pac)