# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1393 - Lajotas Hexagonais
MAX = 42
f = [0] * MAX
def fib(n):
    if n == 0: return 0
    if n == 1 or n == 2: 
        f[n] = 1
        return f[n]
    if f[n]: return f[n]
    if n&1:
        k = (n+1) // 2
        f[n] = fib(k)**2 + fib(k-1)**2
    else:
        k = n // 2
        f[n] = (2*fib(k-1) + fib(k)) * fib(k)
    return f[n]

while True:
    n = int(input())
    if n == 0: break
    print(fib(n+1))