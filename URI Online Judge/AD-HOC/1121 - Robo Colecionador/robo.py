# -*- coding: utf-8 -*-
# URI 1121 - Robo Colecionador
while True:
    N, M, S = map(int, input().split())
    if N == 0 and M == 0 and S == 0:
        break
    matriz = [['#' for _ in range(M+2)] for _ in range(N+2)]
    x = y = 0
    direcao = ""
    for i in range(N):
        linha = input()
        for j in range(M):
            matriz[i+1][j+1] = linha[j]
            if linha[j] == 'N':
                direcao = 'N'
                y, x = i+1, j+1
            elif linha[j] == 'S':
                direcao = 'S'
                y, x = i+1, j+1
            elif linha[j] == 'L':
                direcao = 'L'
                y, x = i+1, j+1
            elif linha[j] == 'O':
                direcao = 'O'
                y, x = i+1, j+1
    colect = 0

    inst = input()
    if 'F' not in inst:
        print(0)
    else:
        for i in range(len(inst)):
            if inst[i] == 'E':
                if direcao == 'N':
                    direcao = 'O'
                elif direcao == 'O':
                    direcao = 'S'
                elif direcao == 'S':
                    direcao = 'L'
                else:
                    direcao = 'N'
            elif inst[i] == 'D':
                if direcao == 'N':
                    direcao = 'L'
                elif direcao == 'L':
                    direcao = 'S'
                elif direcao == 'S':
                    direcao = 'O'
                else:
                    direcao = 'N'
            else:
                x_or, y_or = x, y
                if direcao == 'N':
                    y -= 1
                elif direcao == 'S':
                    y += 1
                elif direcao == 'O':
                    x -= 1
                elif direcao == 'L':
                    x += 1
                if matriz[y][x] == "#":
                    x, y = x_or, y_or
                if matriz[y][x] == '*':
                    colect += 1
                    matriz[y][x] = '.'
        print(colect)