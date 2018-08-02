a, b, c = map(int, input().split())
if a < b + c and b < a + c and c < a + b:
    if a == b == c:
        print("Valido-Equilatero")
    elif a == b and a != c or a == c and a != b or b == c and b != a:
        print("Valido-Isoceles")
    else:
        print("Valido-Escaleno")
    if (a ** 2) == (b ** 2) + (c ** 2) or (b ** 2) == (a **2) + (c **2) or (c ** 2) == (a ** 2) + (b ** 2):
        print("Retangulo: S")
    else:
        print("Retangulo: N")
else:
    print("Invalido")