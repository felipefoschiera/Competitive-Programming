# -*- coding: utf-8 -*-

while True:
    try:
        num = int(input())
        diag_principal = 0
        diag_secundaria = num - 1
        for i in range(num):
            linha = ''
            for j in range(num):
                if j == diag_secundaria:
                    linha += '2'
                elif j == diag_principal:
                    linha += '1'
                else:
                    linha += '3'
            diag_principal += 1
            diag_secundaria -= 1
            print(linha)     
    except:
        break