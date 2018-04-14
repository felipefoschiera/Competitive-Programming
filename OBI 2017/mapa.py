N, M = map(int, input().split())
matriz = [['.' for _ in range(M+2)] for _ in range(N+2)]
'''
Existem duas linhas e duas colunas a mais para
não ser necessário verificar as bordas
'''
y = x = 0
for i in range(N):
    linha = input()
    for c in range(M):
        if linha[c] == 'o':
            y, x = i+1, c+1
        matriz[i+1][c+1] = linha[c]
while True:
    matriz[y][x] = '.'
    if matriz[y-1][x] == 'H':
        y -= 1
    elif matriz[y+1][x] == 'H':
        y += 1
    elif matriz[y][x-1] == 'H':
        x -= 1
    elif matriz[y][x+1] == 'H':
        x += 1
    else:
        break
print(y, x)