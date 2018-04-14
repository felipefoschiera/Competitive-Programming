
def trocoPossivel(valor):
    quant = 0
    #Notas de 100
    quant_100 = int(valor/100)
    valor -= quant_100 * 100
    quant += quant_100
    #Notas de 50
    quant_50 = int(valor/50)
    valor -= quant_50 * 50
    quant += quant_50
    #Notas de 20
    quant_20 = int(valor/20)
    valor -= quant_20 * 20
    quant += quant_20
    #Notas de 10
    quant_10 = int(valor/10)
    valor -= quant_10 * 10
    quant += quant_10
    #Notas de 5
    quant_5 = int(valor/5)
    valor -= quant_5 * 5
    quant += quant_5
    #Notas de 2
    quant_2 = int(valor/2)
    valor -= quant_2 * 2
    quant += quant_2
    if quant == 2:
        return "possible"
    else:
        return "impossible"

while True:
    notas = input()
    if notas == "0 0":
        break
    pago, custo = map(int, notas.split())
    troco = custo - pago
    print(trocoPossivel(troco))