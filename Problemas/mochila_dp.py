def knapSack(W, w, v, n):
    if ks[n-1][W] != 0:
        return ks[n-1][W]
    if n == 0 or W == 0:
        return 0
    if w[n-1] > W:
        result = knapSack(W, w, v, n-1)
    else:
        result = max(v[n-1] + knapSack(W-w[n-1], w, v, n-1),
                     knapSack(W, w, v, n-1))
    ks[n-1][W] = result
    return result

# Mochila com soma dos pesos colocados


def knapsack(W, wt, v, n):
    ks = [[0 for _ in range(W+1)] for _ in range(n+1)]
    for i in range(n+1):
        for w in range(W+1):
            if i == 0 or w == 0:
                ks[i][w] = 0
            elif wt[i-1] <= w:
                ks[i][w] = max(v[i-1] + ks[i-1][w-wt[i-1]], ks[i-1][w])
            else:
                ks[i][w] = ks[i-1][w]
    res = ks[n][W]
    print(res)
    soma_pesos = 0
    w = W
    for i in range(n, 0, -1):
        if res <= 0:
            break
        if res == ks[i-1][w]:
            continue
        else:
            soma_pesos += wt[i-1]
            res -= v[i-1]
            w -= wt[i-1]
    print(soma_pesos)
