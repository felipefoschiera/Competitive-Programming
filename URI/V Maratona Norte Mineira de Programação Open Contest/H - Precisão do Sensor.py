# -*- coding: utf-8 -*-
while True:
    try:
        H, M = map(int, input().split())
        n = H*60 // M
        sensores = list(map(float, input().split()))
        avg = sum(sensores) / n
        soma = 0
        for i in range(n):
            soma += (sensores[i] - avg) ** 2
        precisao = (soma / (n-1)) ** 0.5
        print("{:.5f}".format(precisao))
    except EOFError: break
