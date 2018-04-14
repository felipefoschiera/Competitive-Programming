import sys
for num in sys.stdin:
    num = int(num)
    if num == 0:
        break
    lista = []
    for i in reversed(range(1, num + 1)):
        lista.append(i)
    discarded = []
    while len(lista) != 1:
        discarded.append(lista.pop())
        lista.insert(0, lista.pop())
    print("Discarded cards: ", end="")
    for d in discarded:
        if d != discarded[-1]:
            print("{},".format(d), end = " ")
        else:
            print(d)
    print("Remaining card:", lista[0])