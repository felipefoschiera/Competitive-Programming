# -*- coding: utf-8 -*-
# URI 1804 - Precisa-se de Matemáticos em Marte
# Exemplo de uso de Fenwick Tree (Binary Indexed Tree)

'''
 3 | 0011
-3 | 1101
 & | 0001
'''
import sys

# bit 1 menos significativo de S
def LSOne(S):
    return (S & (-S))

class FenwickTree:
    def __init__(self, n):
        self.__ft = [0] * (n + 1)
    
    # RSQ = Range Sum Query
    def rsq(self, b):
        sum = 0
        while b > 0:
            sum += self.__ft[b]
            b -= LSOne(b)
        return sum

    # __rsq = rsq

    # def rsq(self, a, b):
    #     return self.__rsq(b) - (0 if a == 1 else self.__rsq(a-1))

    def update(self, k, v):
        while k < len(self.__ft):
            self.__ft[k] += v
            k += LSOne(k)

def main():
    N = int(input())
    v = list(map(int, input().split()))
    bit = FenwickTree(N)
    for k in range(N):
        bit.update(k+1, v[k])
    for line in sys.stdin:
        q, i = line.split()
        i = int(i)
        if q == 'a':
            bit.update(i, -v[i-1])
            v[i-1] = 0
        if q == '?':
            print(bit.rsq(i-1))

main() 
