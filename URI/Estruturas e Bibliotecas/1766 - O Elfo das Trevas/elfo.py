# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1766 - O Elfo das Trevas
T = int(input())
for t in range(T):
    N, M = map(int, input().split())
    renas = []
    for _ in range(N):
        nome, peso, idade, altura = input().split()
        peso, idade, altura = int(peso), int(idade), float(altura)
        renas.append([nome, peso, idade, altura])
    renas.sort(key = lambda l: (-l[1], l[2], l[3], l[0]))
    print("CENARIO {%d}" % (t+1))
    for i in range(M):
        print("{} - {}".format(i+1, renas[i][0]))
    