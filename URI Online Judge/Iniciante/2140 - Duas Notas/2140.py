notas = [100, 50, 20, 10, 5, 2]
def trocoPossivel(valor):
    quant = 0
    for n in notas:
        q = valor // n
        valor %= n
        quant += q
    if quant == 2:
        return "possible"
    return "impossible"

while True:
    vals = input()
    if vals == "0 0":
        break
    pago, custo = map(int, vals.split())
    troco = custo - pago
    print(trocoPossivel(troco))