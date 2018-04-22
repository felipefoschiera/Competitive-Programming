# import sys
# sys.setrecursionlimit(10000)
# N = 7000
# ready = [False] * (N+1)
# value = [0] * (N+1)
# coins = [1, 2, 3]
# def solve(x):
#     if x < 0: return float("inf")
#     if x == 0: return 0
#     if ready[x] == True: return value[x]
#     best = float("inf")
#     for c in coins:
#         best = min(best, solve(x-c) + 1)
#     value[x] = best
#     ready[x] = True
#     return best

# print(solve(6151))

coins = [1, 5, 10, 15, 25, 50]
def coin(n):
    value = [0] * (n+1)
    for i in range(1, n+1):
        value[i] = float("inf")
        for c in coins:
            if i-c >= 0:
                value[i] = min(value[i], value[i-c]+1)
    return value[n]
print(coin(100))