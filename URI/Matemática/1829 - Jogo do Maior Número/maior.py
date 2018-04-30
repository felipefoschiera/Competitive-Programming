# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1829 - Jogo do Maior Número
'''
https://math.stackexchange.com/a/1357967
'''
import math
N = int(input())
lucas = 0
rodadas = []
for _ in range(N):
    base, pot = map(int, input().split('^'))
    fat = int(input().rstrip('!'))
    calc1 = pot * math.log(base)
    calc2 = (1/2 * math.log(2*math.pi)) + ((fat + 1/2) * math.log(fat)) - fat
    if calc1 > calc2:
        lucas += 1
        rodadas.append('l')
    else:
        rodadas.append('p')
if lucas > N - lucas:
    print("Campeao: Lucas!")
elif lucas == N - lucas:
    print("A competicao terminou empatada!")
else:
    print("Campeao: Pedro!")
for i in range(1, N+1):
    print("Rodada #{}: {} foi o vencedor".format(i, ("Lucas" if rodadas[i-1] == 'l' else "Pedro")))
