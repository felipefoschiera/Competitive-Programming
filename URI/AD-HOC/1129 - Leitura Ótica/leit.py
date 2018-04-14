# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1129 - Leitura Ótica
while True:
    N = int(input())
    if N == 0:
        break
    for _ in range(N):
        marcadas = [0, 0, 0, 0, 0]
        respostas = list(map(int, input().split()))
        for r in range(len(respostas)):
            if respostas[r] <= 127:
                marcadas[r] = 1
        if marcadas.count(1) > 1 or marcadas.count(1) < 1:
            print("*")
        else:
            indice = marcadas.index(1)
            if indice == 0:
                print("A")
            elif indice == 1:
                print("B")
            elif indice == 2:
                print("C")
            elif indice == 3:
                print("D")
            else:
                print("E")
        