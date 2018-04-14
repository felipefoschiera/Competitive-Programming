import sys
MAX = 1000
memo = [None for i in range(MAX)]
def fib(n):
    if memo[n] == None:
        memo[n] = n if n <= 1 else fib(n-1) + fib(n-2)
    return memo[n]
 