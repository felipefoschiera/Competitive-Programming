# URI 2222 - Brincando com Conjuntos

instances = int(input())
for _ in range(instances):
    quant_conjuntos = int(input())
    conjuntos = []
    for i in range(quant_conjuntos):
        numeros = list(map(int, input().split()))
        conjuntos.append(numeros)
    operacoes = int(input())
    for i in range(operacoes):
        tipo, x, y = map(int, input().split())
        if tipo == 1: #Intersecção - quant. elementos nos dois
            count = 0
            for el in list(set(conjuntos[x - 1])):
                if el in conjuntos[y - 1]:
                    count += 1
            print(count)
        else: # União - quant. elementos diferentes
            todos = []
            for el in list(set(conjuntos[x - 1])):
                todos.append(el)
            for el in list(set(conjuntos[y - 1])):
                todos.append(el)
            todos = list(set(todos))
            print(len(todos))  
                    