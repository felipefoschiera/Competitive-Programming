# -*- coding: utf-8 -*-

import sys
def isPrime(N):
    if N == 2 or N == 3: return True
    if N < 2 or N % 2 == 0: return False
    raiz = int(N ** 0.5)
    for i in range(3, raiz + 1, 2):
        if N % i == 0:
            return False
    return True

peso = int(input())
quant = velocidade = 0

for i in range(peso, sys.maxsize ** 10):
    if isPrime(i):
        velocidade += i
        quant += 1
        if quant == 10:
            break
tempo_h = int(60000000 / velocidade)
tempo_dias = int(tempo_h / 24)
print(velocidade, 'km/h')
print(tempo_h, 'h /', tempo_dias, 'd')