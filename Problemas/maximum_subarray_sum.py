array = [-1, 2, 4, -3, 5, 2, -5, 2]
# Maior soma sequencial é 10 (2, 4, -3, 5, 2)
n = len(array)
best = soma = 0

for i in range(n):
    # Maior valor entre adicionar o número ou começar por ele
    soma = max(array[i], soma+array[i])
    best = max(best, soma)

print(best)
