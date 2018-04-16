'''
Aplicações:
    - URI 1030: A Lenda de Flavious Josephus
    - URI 1031: Crise de Energia
    - URI 1032: O Primo de Josephus
'''
def pesquisa_passo(lista, passo):
    indice = passo - 1 
    while len(lista) > 1: 
        if indice >= len(lista):
            # Se passamos do limite da lista, voltamos ao começo com o passo
            # Ex: 6(0 - 5) elementos, pula até o 7, então volta para o 1 (7 % 6)
            indice = indice % len(lista) 
        del lista[indice]
        indice += passo - 1
    return lista[0]
     