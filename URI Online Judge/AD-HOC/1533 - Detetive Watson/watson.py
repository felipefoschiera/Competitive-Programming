# -*- coding: utf-8 -*-

def segundo_maior(lista):
    temp_list = list(lista)
    temp_list.sort(reverse = True)
    second = temp_list[1]
    return lista.index(second) + 1

while True:
    try:
        quant = int(input())
        if quant == 0:
            break
        suspeitos = list(map(int, input().split()))
        print(segundo_maior(suspeitos))

    except:
        break

