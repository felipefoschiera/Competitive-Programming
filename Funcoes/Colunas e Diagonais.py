def coluna(lista, i):
    # Retorna o elemento i de cada linha = coluna i
    return [row[i] for row in lista]


def diagonal_principal(matriz):
    return [matriz[i][i] for i in range(len(matriz))]
    '''
    matriz[0][0], matriz[1][1], matriz[2][2]...
    '''


def diag_secundaria(matriz):
    return [matriz[i][-i-1] for i in range(len(matriz))]
    '''
    Para cada valor de i(por linha), mostrar matriz[i][-i-1] ex:
    matriz[0][-0-1] -> matriz[0][-1] (último elemento da primeira linha)
    matriz[1][-1-1] -> matriz[0][-2] (penúltimo elemento da segunda linha)
    matriz[2][-2-1] -> matriz[0][-3] (antepenúltimo elemento da terceira linha)
    '''
