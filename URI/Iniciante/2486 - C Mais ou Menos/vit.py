alimentos = {
    'suco de laranja': 120,
    'morango fresco': 85,
    'mamao': 85,
    'goiaba vermelha': 70,
    'manga': 56,
    'laranja': 50,
    'brocolis': 34
}

MIN, MAX = 110, 130

while True:
    T = int(input())
    if T == 0:
        break
    quant_consumida = 0
    for _ in range(T):
        dados = input().split(' ', 1)
        N = int(dados[0])
        alimento = dados[1]
        mg_alimento = alimentos[alimento]
        quant_consumida += N * mg_alimento

    if quant_consumida >= MIN and quant_consumida <= MAX:
        print(quant_consumida, 'mg')
    elif quant_consumida < MIN:
        diferenca = MIN - quant_consumida
        print('Mais', diferenca, 'mg')
    else:
        diferenca = quant_consumida - MAX
        print('Menos', diferenca, 'mg')
        