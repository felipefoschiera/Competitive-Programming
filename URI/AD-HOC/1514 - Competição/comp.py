# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1514 - Competição
def ngmResolveuTodos(problemas, n, m):
    cnt = 0
    resolveuTodos = False
    resolveuNenhum = False
    for i in range(n):
        if sum(problemas[i]) == m:
            resolveuTodos = True
        if sum(problemas[i]) == 0:
            resolveuNenhum = True
    if not resolveuTodos: cnt += 1
    if not resolveuNenhum: cnt += 1
    return cnt

def todosResolvidos(problemas, n, m):
    cnt = 0
    todoProbResolvido = True
    resolvPorTodos = False
    for i in range(m):
        resps = [row[i] for row in problemas]
        if sum(resps) == 0: todoProbResolvido = False
        if sum(resps) == n: resolvPorTodos = True
    if todoProbResolvido: cnt += 1
    if not resolvPorTodos: cnt += 1
    return cnt

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0: break
    problemas = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(n):
        prob = list(map(int, input().split()))
        for j in range(m):
            problemas[i][j] = prob[j]
    cnt = 0
    cnt += ngmResolveuTodos(problemas, n, m)
    cnt += todosResolvidos(problemas, n, m)

    print(cnt)