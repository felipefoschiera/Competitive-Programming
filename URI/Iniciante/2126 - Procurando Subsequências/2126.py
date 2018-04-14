caso = 0
while True:
    try:
        sequencia = input()
        numero = input()
        count = 0
        pos = 0
        if sequencia in numero:
            count += numero.count(sequencia)
            pos = numero.rfind(sequencia) + 1
        caso += 1
        print("Caso #{}:".format(caso))
        if count > 0:
            print("Qtd.Subsequencias:", count)
            print("Pos:", pos)
        else:
            print("Nao existe subsequencia")
        print()
    except:
        break