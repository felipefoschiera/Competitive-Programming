def Sort(lista, tamanho):
    count = 0
    i = 1
    while i < tamanho:
        j = i
        while j > 0 and lista[j-1] > lista[j]:
            lista[j], lista[j-1] = lista[j-1], lista[j]
            count += 1
            j -= 1
        i += 1
    return count

N = int(input())
for _ in range(N):
    tamanho = int(input())
    vagoes = list(map(int, input().split()))
    print("Optimal train swapping takes {} swaps.".format(Sort(vagoes, tamanho)))