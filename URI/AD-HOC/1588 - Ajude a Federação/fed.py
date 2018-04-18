# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1588 - Ajude a Federação
class Team:
    def __init__(self, name, indice, pontos, gols, wins):
        self.name, self.indice, self.pontos, self.gols, self.wins = name, indice, pontos, gols, wins

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    times = [None] * N
    inds = {}
    for i in range(N):
        nome = input()
        team = Team(nome, i, 0, 0, 0)
        times[i] = team
        inds[nome] = i
    for i in range(M):
        gA, tA, gB, tB = input().split()
        gA, gB = int(gA), int(gB)
        if gA > gB:
            times[inds[tA]].pontos += 3
            times[inds[tA]].wins += 1
        elif gA == gB:
            times[inds[tA]].pontos += 1
            times[inds[tB]].pontos += 1
        else:
            times[inds[tB]].pontos += 3
            times[inds[tB]].wins += 1
        times[inds[tA]].gols += gA
        times[inds[tB]].gols += gB

    times.sort(key = lambda l: (l.pontos, l.wins, l.gols), reverse = True)

    for i in range(N):
        print(times[i].name)