# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2044 - Em Dívida
while True:
    n = int(input())
    if n == -1: break
    qt = soma = 0
    vals = list(map(int, input().split()))
    for v in vals:
        soma += v
        if soma % 100 == 0: qt += 1
    print(qt)