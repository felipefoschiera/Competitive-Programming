# -*- coding: utf-8 -*-

while True:
    try:
        N, K = map(int, input().split())
        notas = list(map(int, input().split()))
        medias = []
        for i in range(N):
            for j in range(i):
                for k in range(j):
                    media = (notas[i] + notas[j] + notas[k]) / 3
                    medias.append(media)
        medias.sort(reverse = True)
        print("{:.1f}".format(medias[K-1]))
    except EOFError:
        break