# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2187 - Bits Trocados

t = 1
while True:
    v = int(input())
    if v == 0: break
    notas = [50, 10, 5, 1]
    quant = [0] * 4
    for i in range(4):
        q = v // notas[i]
        v %= notas[i]
        quant[i] = q
    print("Teste", t)
    t += 1
    print(' '.join(map(str, quant)))
    print()