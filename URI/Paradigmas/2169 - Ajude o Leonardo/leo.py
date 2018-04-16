# -*_ coding: utf-8 -*-
# Felipe G. Foschiera
# URI 2169 - Ajude o Leonardo

def knapsack(W, wg, val, n):
    if ks[n-1][W] != 0: return ks[n-1][W]
    if W == 0 or n == 0: return 0
    if wg[n-1] > W:
        result = knapsack(W, wg, val, n-1)
    else:
        result = max(val[n-1] + knapsack(W-wg[n-1], wg, val, n-1), knapsack(W, wg, val, n-1))
    ks[n-1][W] = result
    return result

pot_bala = {
    "HANDGUN": 2,
    "RED9": 3.5,
    "BLACKTAIL": 3.5,
    "MATILDA": 2,
    "HANDCANON": 60,
    "HANDCANNON": 60,
    "STRIKER": 12,
    "TMP": 1.2,
    "RIFLE": 12
}

forca = {
    'GANADOS': 50,
    'COBRAS': 40,
    'ZEALOT': 75,
    'COLMILLOS': 60,
    'GARRADOR': 125,
    'LASPLAGAS': 100,
    'GATLINGMAN': 150,
    'REGENERATOR': 250,
    'ELGIGANTE': 500,
    'DR.SALVADOR': 350
}

while True:
    try:
        qA = int(input())
        vals, pesos = [], []
        for _ in range(qA):
            arma, mun = input().split()
            mun = int(mun)
            potencia = pot_bala[arma] * mun
            vals.append(potencia)
            pesos.append(mun)
        forca_total = 0
        qM = int(input())
        for _ in range(qM):
            monstro, qt = input().split()
            qt = int(qt)
            forca_total += qt * forca[monstro]
        qB = int(input())
        ks = [[0 for _ in range(qB+1)] for _ in range(qA+1)]
        pot_maxima = knapsack(qB, pesos, vals, qA)
        if pot_maxima >= forca_total:
            print("Missao completada com sucesso")
        else:
            print("You Are Dead")
        print()
    except EOFError:
        break