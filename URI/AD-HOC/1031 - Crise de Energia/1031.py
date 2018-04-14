
def pesquisa_numero(lista, passo):
    posicao = 0
    temp_lista = list(lista)
    while len(temp_lista) > 1:
        if posicao >= len(temp_lista):
            posicao = posicao % len(temp_lista)
        if temp_lista[posicao] == 13:
            return pesquisa_numero(lista, passo + 1)
        del temp_lista[posicao]
        posicao += passo - 1
    if temp_lista[0] == 13:
        return passo
    
            

while True:
    try:
        num = int(input())
        lista = list(range(1, num + 1))
        print(pesquisa_numero(lista, 1))
    except:
        break
