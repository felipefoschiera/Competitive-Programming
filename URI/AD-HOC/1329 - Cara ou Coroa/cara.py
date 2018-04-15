# -*- coding: utf-8 -*-

while True:
    try:
        quant = input()
        if quant == "0":
            break
        quant = int(quant)
        jogos = list(map(int, input().split()))
        maria, joao = jogos.count(0), jogos.count(1)
        print("Mary won {} times and John won {} times".format(maria, joao))
    except:
        break