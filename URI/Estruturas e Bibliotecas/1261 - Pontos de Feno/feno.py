# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1261 - Pontos de Feno
while True:
    try:
        M, N = map(int, input().split())
        palavras = {}
        for _ in range(M):
            pal, valor = input().split()
            valor = int(valor)
            palavras[pal] = valor
        for _ in range(N):
            soma = 0
            while True:
                linha = input()
                if linha == '.': break
                linha = linha.split()
                for word in linha:
                    if word in palavras:
                        soma += palavras[word]
            
            print(soma)

    except EOFError:
        break