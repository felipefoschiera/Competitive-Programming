N, C, M = map(int, input().split())
carimbadas = [0] * 112
car = list(map(int, input().split()))
for f in car:
    carimbadas[f] = 1
faltam = C
tem = list(map(int, input().split()))
for f in tem:
    if(carimbadas[f] == 1):
        faltam -= 1
        carimbadas[f] = 0
print(faltam)
