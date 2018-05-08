lista = [[]]
lista.sort(key=lambda l: (l[0], -l[1]), reverse=True)
'''
Ordena a lista primeiro por l[0] do maior para o menor e depois por l[1] do menor para o maior.
Se os valores são números e quer-se ordenar do maior para o menor,
pode-se negativar o elemento.
Também pode-se utilizar o reverse = True,
mas este é aplicado a todos os elementos.
'''
