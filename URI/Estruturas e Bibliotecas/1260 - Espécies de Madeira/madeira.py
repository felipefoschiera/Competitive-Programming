# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1260 - Espécies de Madeira
N = int(input())
for i in range(N):
    if i == 0: blank = input()    
    arvores = {}    
    total = 0
    while True:
        try:
            arv = input()
            if arv == "": break
            if arv not in arvores:
                arvores[arv] = 1
            else:
                arvores[arv] += 1
            total += 1
        except EOFError:
            break
    if i != 0: print()
    for a in sorted(arvores):
        print("{} {:.4f}".format(a, arvores[a] / total * 100))