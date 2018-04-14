tests = int(input())
for _ in range(tests):
    qt_alunos = int(input())
    notas = list(map(int, input().split()))
    ordem_chegada = list(notas)
    permanecem = 0
    notas.sort(reverse = True) # 100 90 80
    for i in range(len(notas)):
        if notas[i] == ordem_chegada[i]:
            permanecem += 1
    print(permanecem)