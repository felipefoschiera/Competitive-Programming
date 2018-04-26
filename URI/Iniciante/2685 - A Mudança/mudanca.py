# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URi 2685 - A Mudança
# Problema bugado do capiroto que me deixou pistolaço ja
while True:
    try:
        grau = int(input())
        if grau < 0 or grau > 360:
            pass
        else:
            if grau < 90 or grau == 360:
                print("Bom Dia!!")
            elif grau < 180:
                print("Boa Tarde!!")
            elif grau < 270:
                print("Boa Noite!!")
            elif grau < 360:
                print("De Madrugada!!")
    except EOFError:
        break