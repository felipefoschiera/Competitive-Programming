# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1212 - Aritmética Primária
def countCarry(a, b):
    carries = x = y = aux = 0
    while True:
        x, y = a % 10, b % 10 # Pegamos os últimos digitos de a e de b
        a //= 10 # E dividimos por 10 para excluir os últimos digitos do novo número
        b //= 10
        if x + y + aux >= 10: # Se a soma dos últimos digitos + auxiliar ultrapassa ou iguala 10
            carries += 1 # Temos um carry, e portanto um auxiliar 1 para o próximo cálculo
            aux = 1
        else: aux = 0 #Se não ultrapassa, volta a zero.
        if a == 0 and b == 0: break
    return carries
            
while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0: break
    carry = countCarry(a, b)
    if carry == 0: print("No carry operation.")
    elif carry == 1: print("1 carry operation.")
    else: print(carry, "carry operations.")