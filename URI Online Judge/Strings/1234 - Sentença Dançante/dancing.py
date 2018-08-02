while True:
    try:
        frase = list(input())
        estado = 0
        nova_frase = ""
        for char in frase:
            if char.isdigit() or char == ' ':
                nova_frase += char
                continue
            if estado == 0:
                nova_frase += char.upper()
                estado = 1
            else:
                nova_frase += char.lower()
                estado = 0
        print(nova_frase)   
    except:
        break