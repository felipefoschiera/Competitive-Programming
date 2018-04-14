while True:
    quant = int(input())
    if quant == 0:
        break
    divisor = list(map(int, input().split()))
    N, M = divisor
    for _ in range(quant):
        coord = list(map(int, input().split()))
        X, Y = coord
        if X == N or Y == M:
            print('divisa')
        else:
            posicao = ''
            if Y > M:
                posicao += 'N'
            else:
                posicao += 'S'
            if X > N:
                posicao += 'E'
            else:
                posicao += 'O'
            print(posicao)