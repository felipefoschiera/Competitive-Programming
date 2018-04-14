# Potenciação: 'b' elevado a 'n'
def pot(b, n):
    if n == 0: return 1
    if n == 1: return b
    if n % 2 == 0:
        return pot(b, n/2) ** 2
    else:
        return b * pot(b, n-1)

'''
Exemplo:

3 ** 17
pot(3, 17) = 3 * pot(3, 16)     -> 3 * 43046721 = 129140163
pot(3, 16) = pot(3, 8) ** 2     -> 6561 ** 2 = 43046721
pot(3, 8) = pot(3, 4) ** 2      -> 81 ** 2 = 6561
pot(3, 4) = pot(3, 2) ** 2      -> 9 ** 2 = 81
pot(3, 2) = pot(3, 1) ** 2      -> 3 ** 2 = 9
pot(3, 1) = 3
'''
 