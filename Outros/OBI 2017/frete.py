from collections import defaultdict
from heapq import heappop, heappush


def dijkstra(edges, s, f):
    g = defaultdict(list)
    for a, b, c in edges:
        g[a].append((c, b))
        g[b].append((c, a))

    q = [(0, s)]
    seen = set()
    while q:
        (cost, v1) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            if v1 == f:
                return cost
            for c, v2 in g.get(v1):
                if v2 not in seen:
                    heappush(q, (cost+c, v2))

    return float("inf")


N, M = map(int, input().split())
edges = []
for _ in range(M):
    a, b, c = map(int, input().split())
    edges.append((a, b, c))

print(dijkstra(edges, 1, N))
