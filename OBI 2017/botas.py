MAX = 31
while True:
    try:
        pares = 0
        esq = [0] * MAX
        direita = [0] * MAX
        N = int(input())
        for _ in range(N):
            M, C = input().split()
            M = int(M)
            if C == 'E':
                esq[M - 30] += 1
            else:
                direita[M - 30] += 1
        for i in range(MAX):
            _esq = esq[i]
            _dir = direita[i]
            pares += min(_esq, _dir)
        print(pares)
    except:
        break
