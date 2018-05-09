# Maior Divisor Comum entre A e B, forma iterativa
def mdc(a, b):
    resto = None
    while resto != 0:
        resto = a % b
        a = b
        b = resto
    return a

# Maior Divisor Comum entre A e B, forma recursiva


def mdc_recursivo(a, b):
    if b == 0:
        return a
    return mdc_recursivo(b, a % b)


# Menor Múltiplo Comum
def mmc(a, b):
    return a*b / mdc(a, b)
    # Ex: mmc de 15 e 20 é 60, pois 300 / 5 = 60

# MMC de ARRAY


def mmcArray(array):
    a, b = array[0], array[1]
    lcm = mmc(a, b)
    for i in range(2, len(array)):
        lcm = mmc(lcm, array[i])
