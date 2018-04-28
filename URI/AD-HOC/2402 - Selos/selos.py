# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2402 - Selos
def isPrime(n):
    if n == 2 or n == 3: return True
    if n % 2 == 0 or n < 2: return False
    raiz = int(n ** 0.5)
    for i in range(3, raiz+1, 2):
        if n % i == 0: return False
    return True

n = int(input())
if n < 4: print("N")
else: print("S" if not isPrime(n) else "N")