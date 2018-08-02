while True:
    try:
        num_pessoas, relacoes, minimo = map(int, input().split())
        quant_amigos = {}
        for _ in range(relacoes):
            a, b = map(int, input().split())
            if a in quant_amigos:
                quant_amigos[a] += 1
            else:
                quant_amigos[a] = 1
            if b in quant_amigos:
                quant_amigos[b] += 1
            else:
                quant_amigos[b] = 1
        convidados = []
        for pessoa in quant_amigos:
            if quant_amigos[pessoa] >= minimo:
                convidados.append(pessoa)
        convidados.sort()
        if not convidados:
            print(0)
        else:
            for c in range(len(convidados)):
                if c != len(convidados) - 1:
                    print(convidados[c], end = ' ')
                else:
                    print(convidados[c])
                
    except EOFError:
        break