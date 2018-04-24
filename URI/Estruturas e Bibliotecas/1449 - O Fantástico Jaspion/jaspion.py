# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1449 - O Fantástico Jaspion
T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    dicionario = {}
    for _ in range(n):
        jap = input()
        port = input()
        dicionario[jap] = port
    for _ in range(m):
        frase = input().split()
        nova_frase = ""
        for word in range(len(frase)):
            if frase[word] in dicionario:
                nova_frase += dicionario[frase[word]] + " "
            else:
                nova_frase += frase[word] + " "
        nova_frase = nova_frase.strip()
        print(nova_frase)
    print()