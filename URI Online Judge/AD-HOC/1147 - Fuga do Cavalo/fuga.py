# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1147 - Fuga do Cavalo
horizontal_pos = lambda l: ord(l) - ord('a')
posicaoValida = lambda x, y: x >= 1 and x <= 8 and y >= 1 and y <= 8
posicaoSegura = lambda y, x: matriz[y][x] == 0
tc = 0
while True:
    inic = input()
    if inic == '0': break
    cavY, cavX = list(inic)
    cavY = int(cavY)
    cavX = int(horizontal_pos(cavX)) + 1
    matriz = [[0 for _ in range(10)] for _ in range(10)]
    for i in range(8):
        y, x = list(input())
        y, x = int(y), int(horizontal_pos(x)) + 1
        matriz[y][x] = 1
    movX = [2, 2, -2, -2, 1, 1, -1, -1]
    movY = [1, -1, 1, -1, 2, -2, 2, -2]
    count = 0
    for i in range(8):
        new_x, new_y = cavX + movX[i], cavY + movY[i]
        if not posicaoValida(new_x, new_y): continue
        if posicaoSegura(new_y+1, new_x+1) and posicaoSegura(new_y+1, new_x-1): count += 1
    print("Caso de Teste #{}: {} movimento(s).".format(tc+1, count))
    tc += 1