while True:
    try:
        D, VF, VG = map(int, input().split())

        hip = (D*D + 144) ** 0.5
        if hip/VG <= 12/VF:
            print("S")
        else:
            print("N")
    except EOFError:
        break

'''
Se a**2 = b**2 + c**2
E b = 12 (distância até as águas internacionais)
E c = D, distância entre o fugitivo e a guarda,
então a = distância da guarda ao ponto de chegada
do fugitivo.
Se v = d/t, tempo = d / v
Sendo assim, a velocidade da guarda é a / VG
E a velocidade do fugitivo é 12 / VF

'''