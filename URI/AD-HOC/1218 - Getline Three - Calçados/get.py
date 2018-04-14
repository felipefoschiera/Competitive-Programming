# -*- coding: utf-8 -*-
# URI 1218 - Getline Three - Calçados
caso = 0
while True:
    try:
        N = int(input())
        calcados = input().split()
        quant = f = m = 0
        for i in range(0, len(calcados), 2):
            tam = int(calcados[i])
            lado = calcados[i+1]
            if tam == N:
                quant += 1
                if lado == 'F':
                    f += 1
                else:
                    m += 1
        caso += 1
        if caso != 1:
            print()
        print("Caso {}:".format(caso))
        print("Pares Iguais:", quant)
        print("F:", f)
        print("M:", m)       
    except EOFError:
        break