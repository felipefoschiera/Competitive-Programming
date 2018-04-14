while True:
    try:
        numeros = input()
        if numeros == '0 0':
            break
        A, B = list(map(int, numeros.split()))
        alice = list(map(int, input().split()))
        beatriz = list(map(int, input().split()))
        a_unicas = list(set(alice))
        b_unicas = list(set(beatriz))  

        menor = min(a_unicas, b_unicas)
        maior = max(a_unicas, b_unicas)
        for i in range(len(maior)):
            if maior[i] in menor:
                menor.remove(maior[i])
        print(len(menor))
    except:
        break