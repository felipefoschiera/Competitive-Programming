def LSOne(S):
    return (S & (-S))

class FenwickTree:
    def __init__(self, n):
        self.__ft = [0] * (n + 1)

    def adjust(self, k, v):
        while k < len(self.__ft):
            self.__ft[k] += v
            k += LSOne(k)
    
    def rsq(self, b):
        soma = 0
        while b > 0:
            soma += self.__ft[b]
            b -= LSOne(b)
        return soma

N, Q = map(int, input().split())
v = list(map(int, input().split()))
bit = FenwickTree(N)
for k in range(N):
    bit.adjust(k + 1, v[k])
for _ in range(Q):
    dados = list(map(int, input().split()))
    q = dados[0]
    k = dados[1]
    if q == 1:
        print(bit.rsq(k))
    else:
        p = dados[2]
        bit.adjust(k, p - v[k-1])
        v[k-1] = p
        