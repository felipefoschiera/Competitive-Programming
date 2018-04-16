# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1025 - Onde está o Mármore?
from bisect import bisect_left
def find(lista, valor):
    index = bisect_left(lista, valor)
    if index < len(lista) and lista[index] == valor:
        return index + 1
    return -1

case = 1
while True:
    N, Q = map(int, input().split())
    if N == 0 and Q == 0:
        break
    marmores = []
    for _ in range(N):
        marmores.append(int(input()))
    marmores.sort()
    print("CASE# {}:".format(case))
    case += 1
    for _ in range(Q):
        valor = int(input())
        index = find(marmores, valor)
        if index == -1: print(valor, 'not found')
        else: print(valor, 'found at', index)