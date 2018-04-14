import sys
def procuraVencedor(secreto, lista):
    smaller_diff = sys.maxsize ** 10
    venc_proximo = 0
    for i in range(len(lista)):
        if lista[i] == secreto:
            return i + 1
        diferenca = abs(secreto - lista[i])
        if diferenca < smaller_diff:
            smaller_diff = diferenca
            venc_proximo = i
    return venc_proximo + 1
        
tests = int(input())
for _ in range(tests):
    qt_alunos, secreto = map(int, input().split())
    alunos = list(map(int, input().split()))
    print(procuraVencedor(secreto, alunos))