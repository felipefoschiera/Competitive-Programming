# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1258 - Camisetas
caso = 1
while True:
    n = int(input())
    if n == 0: break
    camisetas = []
    for _ in range(n):
        nome = input()
        cor, tamanho = input().split()
        if tamanho == 'P': tamanho = 1
        elif tamanho == 'M': tamanho = 2
        else: tamanho = 3
        camisetas.append([cor, tamanho, nome])
    camisetas.sort(key = lambda l: (l[0], l[1], l[2]))
    equiv = {
        1: 'P',
        2: 'M',
        3: 'G'
    }
    if caso != 1:
        print()
    caso += 1
    for c in camisetas:
        print(c[0], equiv[c[1]], c[2])