# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1152 - Estradas Escuras
from collections import defaultdict
from heapq import heappop, heappush

def prim(start, g, m):
    cost, pq = 0, []
    visitado = [False] * (m+1)
    for i in range(len(g[start])): # Para cada vértice no grafo de [start]
        heappush(pq, (g[start][i][1], g[start][i][0])) # Adiciona um tuple contendo o peso e a cidade destino
        visitado[start] = True
    while pq: # Enquanto houverem elementos na fila de prioridade
        custo, destino = heappop(pq)
        if visitado[destino] == False:
            cost += custo
            visitado[destino] = True
            for i in range(len(g[destino])): # Para cada vértice no grafo de [destino]
                if visitado[g[destino][i][0]] == False:
                    heappush(pq, (g[destino][i][1], g[destino][i][0])) 
    return cost   
        
    
while True: 
    N, M = map(int, input().split())
    if N == 0 and M == 0: break
    g = defaultdict(list)
    total = 0
    for i in range(M):
        x, y, z = map(int, input().split())
        g[x].append((y, z)) # Grafo de x contém (cidadeDestino, custo)
        g[y].append((x, z))
        total += z
    resp = total - prim(0, g, M)
    print(resp)