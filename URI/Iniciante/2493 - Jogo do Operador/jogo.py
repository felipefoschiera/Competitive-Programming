while True:
    try:
        T = int(input())
        questoes = []
        for i in range(T):
            dados = input().split()
            X = int(dados[0])
            Y,Z = map(int, dados[1].split('='))
            questoes.append([X, Y, Z])
        jogos = []
        for i in range(T):
            dados = input().split()
            Nome, Indice, Operador = dados
            Indice = int(Indice)
            jogos.append([Nome, Indice, Operador])
        nao_passam = []
        for j in jogos:
            questao = questoes[j[1] - 1]
            if j[2] == '+':
                if questao[0] + questao[1] != questao[2]:
                    nao_passam.append(j[0])
            elif j[2] == '-':
                if questao[0] - questao[1] != questao[2]:
                    nao_passam.append(j[0])
            elif j[2] == '*':
                if questao[0] * questao[1] != questao[2]:
                    nao_passam.append(j[0])
            else:
                if questao[0] + questao[1] == questao[2] or questao[0] - questao[1] == questao[2] or questao[0] * questao[1] == questao[2]:
                    nao_passam.append(j[0])
        if len(nao_passam) == 0:
            print("You Shall All Pass!")
        elif len(nao_passam) == T:
            print("None Shall Pass!") 
        else:
            print(' '.join(sorted(nao_passam)))
    except:
        break