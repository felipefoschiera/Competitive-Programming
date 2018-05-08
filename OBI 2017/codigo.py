def valida():
    strings = []
    combinacoes = []
    N = int(input())
    for _ in range(N):
        string = input()
        if combinacoes:
            for c in combinacoes:
                if string in c:
                    return string
        if strings:
            if string in strings:
                return string
            for i in range(len(strings)):
                conc1 = string + strings[i]
                conc2 = strings[i] + string
                combinacoes.append(conc1)
                combinacoes.append(conc2)

        strings.append(string)

    return 'ok'


print(valida())
