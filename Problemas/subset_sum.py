# Subset Sum Recursivo
def isSubsetSum(set, n, sum):

    if sum == 0: return True
    if n == 0 and sum != 0: return False
    if set[n-1] > sum:
        return isSubsetSum(set, n-1, sum)

    return isSubsetSum(set, n-1, sum) or isSubsetSum(set, n-1, sum-set[n-1])

# Subset Sum DP
def subsetSum(st, n, sm):
    subset = [[True for _ in range(sm+1)] for _ in range(n+1)]
    for i in range(n+1): # if sum == 0
        subset[i][0] = True
    
    for i in range(1, sm+1): # if n == 0 and sum != 0
        subset[0][i] = False
    
    for i in range(1, n+1):
        for j in range(1, sm+1):
            if j < st[i-1]: # if set > sum
                subset[i][j] = subset[i-1][j] 
            else:
                subset[i][j] = subset[i-1][j] or subset[i-1][j - st[i-1]]
    return subset[n][sm]
