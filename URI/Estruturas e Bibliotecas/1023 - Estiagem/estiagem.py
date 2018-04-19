# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1023 - Estiagem
cid = 1
while True:
    n = int(input())
    if n == 0: break
    if cid != 1: print()
    consumos = {}
    pessoas = total = 0
    for _ in range(n):
        qt, cons = map(int, input().split())
        pessoas += qt
        total += cons
        media = cons // qt
        if media not in consumos:
            consumos[media] = qt
        else:
            consumos[media] += qt
        
    consumo_medio = total / pessoas
    inteiro, decimal = str(consumo_medio).split('.')
    numero = str(inteiro + '.' + decimal[:2])
    print("Cidade# {}:".format(cid))
    cid += 1
    x = 0
    for c in sorted(consumos):
        if x != len(consumos) - 1:
            print("{}-{}".format(consumos[c], c), end = ' ')
        else:
            print("{}-{}".format(consumos[c], c))
        x += 1
    print("Consumo medio: {:.2f} m3.".format(float(numero)))