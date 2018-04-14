# -*- coding: utf-8 -*-
#URI 1309 - Formatação Monetária
while True:
    try:
        dolares = int(input())
        centavos = int(input())
        cent_str = str(centavos)
        if len(cent_str) == 1:
            cent_str = '0' + cent_str

        money = str(dolares) + '.' + cent_str
        money = float(money)
        print("${:.2f}".format(money))
    except EOFError:
        break