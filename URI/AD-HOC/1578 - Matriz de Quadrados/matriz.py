def column(matriz, i):
    return [row[i] for row in matriz]

count = 4
N = int(input())
for _ in range(N):
    M = int(input())
    matriz = [[0 for _ in range(M)] for _ in range(M)]
    for i in range(M):
        pontos = list(map(int, input().split()))
        for j in range(len(pontos)):
            matriz[i][j] = pontos[j] ** 2
    if count != 4:
        print()
    print("Quadrado da matriz #{}:".format(count))
    count += 1 
    colunas = []
    for i in range(len(matriz)):
        coluna = column(matriz, i)
        longest = max(coluna)
        ll = len(str(longest))
        for j in range(len(coluna)):
            val = str(coluna[j])
            while len(val) != ll:
                val = " " + val
            coluna[j] = val
        colunas.append(coluna)
        
    for i in range(len(colunas)):
        for j in range(len(colunas)):
            if j != len(colunas) - 1:
                print(colunas[j][i], end = ' ')
            else:
                print(colunas[j][i])