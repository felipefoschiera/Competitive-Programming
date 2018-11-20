# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1202 - Festival das Noites Brancas
MAX = 1500
f = [0] * (MAX+1)

def fib(n):
    if n == 0: return 0
    if n == 1 or n == 2:
        f[n] = 1
        return f[n]
    if f[n]: return f[n]
    if n & 1:
        k = (n+1) // 2
        f[n] = fib(k-1) * fib(k-1) + fib(k) * fib(k)
    else:
        k = n // 2
        f[n] = (2*fib(k-1) + fib(k)) * fib(k)
    return f[n]

T = int(input())
for _ in range(T):
    n = int(input(), 2)
    calc = str(fib(n % 1500) % 1000)
    while len(calc) != 3:
        calc = "0" + calc
    print(calc)