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
    if b == 0: return a
    return mdc_recursivo(b, a%b)
 