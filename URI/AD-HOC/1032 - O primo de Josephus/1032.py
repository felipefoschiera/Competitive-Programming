# -*- coding: utf-8 -*-
import sys

def isPrime(num):
    if num == 2 or num == 3: return True
    if num < 2 or num % 2 == 0: return False
    raiz = int(num ** 0.5)
    for i in range(3, raiz + 1, 2):
        if num % i == 0:
            return False
    return True

primos = [2]
for i in range(sys.maxsize ** 10):
    if isPrime(i):
        primos.append(i)
        if len(primos) == 3501:
            break

# 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
def sobrevivente(lista):
    # if len(primos) < len(lista):
    #     while len(primos) != len(lista):
    #         for i in range(primos[-1] + 1, sys.maxsize ** 10):
    #             if isPrime(i):
    #                 primos.append(i)
    #                 break
    posicao = primos[0] - 1
    count = 0
    while len(lista) > 1:
        if posicao >= len(lista):
            posicao = posicao % len(lista)
        del lista[posicao]
        count += 1
        passo = primos[count]
        posicao += passo - 1

    return lista[0]
    

while True:
    try:
        num = input()
        if num == 0:
            break
        num = int(num)
        lista = list(range(1, num + 1))
        print(sobrevivente(lista))
    except:
        break