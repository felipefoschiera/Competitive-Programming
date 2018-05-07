from collections import defaultdict
from heapq import heappop, heappush

def dijkstra(edges, f, t):
    # f = pos inicial, t = posição final
    g = defaultdict(list) # Inicializa um dicionário-lista em branco
    # G irá guardar nosso grafo de cidades e custos
    '''
    Ver https://docs.python.org/2/library/collections.html#collections.defaultdict
    '''
    for l,r,c in edges: # l = inicial/left , r = final/right , c = custo
        g[l].append((c,r)) # índice do inicial no dicionário g passa a ser [(Custo, Final)]
        ''' Linha abaixo se pode ir em qualquer direção e não somente de A -> B '''
        g[r].append((c, l)) # índice do final no dicionário g passa a ser [(Custo, Inicial)]
    q = [(0, f, ())] # q é uma lista contendo um tuple com (0/custo, posição inicial e um tuple vazio)
    seen = set() # set - coleção de elementos únicos vazia
    while q: # enquanto houver um vértice para ser analisado
        (cost,v1,path) = heappop(q) #heappop remove o menor tuple da lista q
        # transformando o tuple (cost, v1, path) para os elementos do menor tuple da lista q in
        if v1 not in seen: # Se o vértice 1 deste menor elemento não foi visitado
            seen.add(v1) # È adicionado á lista de visitados
            path = (v1, path) # v1 é adicionado ao caminho - o vértice mais a esquerda é o último visitado
            #if v1 == t: return (cost, path) # Se o vértice é igual ao vértice final, retornamos o custo e o caminho
            if v1 == t: return cost
            for c, v2 in g.get(v1, ()): # Para cada custo c e vértice final v2 dos vértices conectados a v1
                if v2 not in seen: # Se o vértice v2 não foi visto
                    heappush(q, (cost+c, v2, path))
                    # O custo do caminho mais o custo prévio é adicionado a lista de prioridade,
                    # junto com o vértice final e o caminho 

    return float("inf")

N, M = map(int, input().split())
edges = []
for _ in range(M):
    inic, final, custo = map(int, input().split())
    edges.append((inic, final, custo))

print("1 -> {}:".format(N))
print(dijkstra(edges, 1, N))
