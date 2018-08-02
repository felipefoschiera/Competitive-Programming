# -*- coding: utf-8 -*-
import math

while True:
    try:
        dados = input()
        if dados == '0':
            break  
        leit_dia, dias_adiant, leit_ideal= list(map(int, dados.split()))
        dias_adiant *= leit_dia * leit_ideal
        r = math.floor(dias_adiant / (leit_ideal - leit_dia))
        if r == 1:
            print('1 pagina')
        else:
            print(r, "paginas")
    except EOFError:
        break
