# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2018 - Olimpíadas de Natal
from collections import defaultdict
medalhas = defaultdict(list)
while True:
    try:
        categoria, ouro, prata, bronze = input(), input(), input(), input()
        if ouro not in medalhas:
            medalhas[ouro] = [1, 0, 0]
        else:
            medalhas[ouro][0] += 1        
        if prata not in medalhas:
            medalhas[prata] = [0, 1, 0]
        else:
            medalhas[prata][1] += 1     
        if bronze not in medalhas:
            medalhas[bronze] = [0, 0, 1]
        else:
            medalhas[bronze][2] += 1
    except EOFError:
        break
print("Quadro de Medalhas")
for m in sorted(medalhas.items(), key = lambda x: (-x[1][0], -x[1][1], -x[1][2], x[0])):
    print(m[0], m[1][0], m[1][1], m[1][2])