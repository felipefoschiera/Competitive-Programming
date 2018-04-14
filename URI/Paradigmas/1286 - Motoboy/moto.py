# -*- coding: utf-8 -*-
# URI 1286 - Motoboy
# Felipe G. Foschiera

def knapSack(W, w, v, n):
    result = 0
    if ks[n-1][W] != 0: return ks[n-1][W]
    if n == 0 or W == 0: return 0
    if w[n-1] > W:
        result = knapSack(W, w, v, n-1)
    else:
        result = max(v[n-1] + knapSack(W-w[n-1], w, v, n-1), knapSack(W, w, v, n-1))
    ks[n-1][W] = result
    return result
while True:
    N = int(input())
    if N == 0: break
    P = int(input())
    vals = []
    tempo = []
    for _ in range(N):
        a, b = map(int, input().split())
        tempo.append(a)
        vals.append(b)
    ks = [[0 for _ in range(P+1)] for _ in range(N)]  
    print(knapSack(P, vals, tempo, N), 'min.')