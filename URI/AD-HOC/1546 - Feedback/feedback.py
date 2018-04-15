# -*- coding: utf-8 -*-

responsaveis = {
    1: 'Rolien',
    2: 'Naej',
    3: 'Elehcim',
    4: 'Odranoel'
}
tests = int(input())
for _ in range(tests):
    K = int(input())
    for _ in range(K):
        num = int(input())
        print(responsaveis[num])