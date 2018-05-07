from heapq import heappop, heappush
from collections import defaultdict
INFTO = 1123456789

def dijkstra(s):
    dist[s] = 0
    Q = [(0, s)]
    while Q:
        cost, u = heappop(Q)
        for i in range(len(LG[u])):
            v = LG[u][i][0]
            w = LG[u][i][1]
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heappush(Q, (dist[v], v))

C, V = map(int, input().split())
dist = [INFTO] * C
LG = defaultdict(list)    

for _ in range(V):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    LG[u].append((v, w))
    LG[v].append((u, w))
dijkstra(0)
print(-1 if dist[C-1] == INFTO else dist[C-1])