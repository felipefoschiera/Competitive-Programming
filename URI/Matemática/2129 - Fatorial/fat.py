dig = [1, 1, 2, 6, 4, 2, 2, 4, 2, 8]
def lastNon0Digit(n): #Digito mais a direita do fatorial de n que não é zero
    if n < 10:
        return dig[n]
    if ((n // 10) % 10) % 2 == 0:
        return (6 * lastNon0Digit(n // 5) * dig[n % 10]) % 10
    else:
        return (4 * lastNon0Digit(n // 5) * dig[n % 10]) % 10
    return 0
i = 0
while True:
    try:
        N = int(input())
        i += 1
        print("Instancia", i)
        print(lastNon0Digit(N))
        print()
    except EOFError:
        break
