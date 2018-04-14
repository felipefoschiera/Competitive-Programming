def knapSack(W, w, v, n):
    if ks[n-1][W] != 0: return ks[n-1][W]
    if n == 0 or W == 0: return 0
    if w[n-1] > W:
        result = knapSack(W, w, v, n-1)
    else:
        result = max(v[n-1] + knapSack(W-w[n-1], w, v, n-1), knapSack(W, w, v, n-1))
    ks[n-1][W] = result
    return result