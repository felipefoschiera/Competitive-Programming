# -*- coding: utf-8 -*-

while True:
    try:
        x1, y1, x2, y2 = map(int, input().split())
        movimentos = 0
        if x1 == 0 and y1 == 0 and x2 == 0 and y2 == 0:
            break
        if x1 == x2 and y1 == y2:
            movimentos = 0
        elif x1 == x2 or y1 == y2:
            movimentos = 1
        elif (x2 - x1) == -(y2 - y1) or -(x2 - x1) == -(y2 - y1) or -(x2-x1) == (y2 - y1) or (x2 - x1) == (y1-y1):
            movimentos = 1
        else:
            movimentos = 2
        print(movimentos)
    except EOFError:
        break

