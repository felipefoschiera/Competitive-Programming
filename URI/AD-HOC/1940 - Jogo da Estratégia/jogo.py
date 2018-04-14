# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1940 - Jogo da Estratégia

J, R = map(int, input().split())
pontos = [0] * J
pontuacoes = list(map(int, input().split()))
i = 0
for el in pontuacoes:
    pontos[i] += el
    i += 1
    if i == J:
        i = 0

maior_pontuacao = max(pontos)
ind_vencedor = 0
for p in range(len(pontos)):
    if pontos[p] >= maior_pontuacao:
        ind_vencedor = p

print(ind_vencedor + 1)