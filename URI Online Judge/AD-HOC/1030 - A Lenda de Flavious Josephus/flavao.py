# -*- coding: utf-8 -*-
def pesquisa_passo(lista, n):
    indice = n - 1 
    while len(lista) > 1: 
        if indice >= len(lista):
            indice = indice % len(lista) 
        del lista[indice]
        indice += (n - 1)
    return lista[0]

test_cases = int(input())
for i in range(test_cases):
    pessoas, passo = list(map(int, input().split()))
    lista = list(range(1, pessoas + 1))
    print("Case {}: {}".format(i + 1, pesquisa_passo(lista, passo)))
    