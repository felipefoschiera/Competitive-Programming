# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1800 - Onde Estão Minhas Chaves
Q, E = map(int, input().split())
visitados = set(map(int, input().split()))
for _ in range(Q):
    esc = int(input())
    if esc not in visitados:
        print(1)
        visitados.add(esc)
    else: print(0)