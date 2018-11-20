# -*- coding: utf-8
# Felipe G. Foschiera
# URI 1310 - Lucro
while True:
    try:
        N = int(input())
        custo_dia = int(input())
        soma = best = 0
        for _ in range(N):
            receita = int(input())
            lucro = receita - custo_dia            
            soma = max(lucro, soma+lucro)
            best = max(soma, best)
        print(best)
    except EOFError:
        break
