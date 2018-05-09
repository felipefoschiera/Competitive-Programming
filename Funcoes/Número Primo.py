def isPrime(num):
    if num == 2 or num == 3:
        return True
    if num < 2 or num % 2 == 0:
        return False
    raiz = int(num ** 0.5)
    for i in range(3, raiz + 1, 2):
        if num % i == 0:
            return False
    return True


'''
Só é necessário verificar se N é divisível pelos números i até a raiz de N, 
pois para um número não primo sempre existe um divisor menor que a raiz.
Dado N = a*b para um número N não primo,
é impossível que ambos a e b sejam maiores que a raiz de N
Sendo assim, um deles está antes da raiz.
Ex:
N = 52
Raiz de N = 7.21
Com a = 52, b = 1, b está abaixo da raiz.
Com a = 26, b = 2, b está abaixo da raiz.
Com a = 13, b = 4, b está abaixo da raiz...
'''
