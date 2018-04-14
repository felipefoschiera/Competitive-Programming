'''
Aplicações:
    - URI 1804: Precisa-se de Matemáticos em Marte
    - OBI 2017: Arranha-céu
'''
def LSOne(S):
    return S & (-S)

class FenwickTree:
    def __init__(self, N):
        self.ft = [0] * (N + 1)

    def rsq(self, b):
        soma = 0
        while b > 0:
            soma += self.ft[b]
            b -= LSOne(b)
        return soma

    def update(self, k, v):
        while k < len(self.ft):
            self.ft[k] += v
            k += LSOne(k)

