# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2248 - Estágio
from collections import defaultdict
turma = 1
while True:
    N = int(input())
    if N == 0: break
    maior_media = 0
    medias = defaultdict(list)
    for _ in range(N):
        cod, m = map(int, input().split())
        medias[m].append(cod)
        maior_media = max(maior_media, m)

    select = medias[maior_media]
    print("Turma", turma)
    turma += 1
    for i in range(len(select)):
        print(str(select[i]), end = ' ')
    print('\n')