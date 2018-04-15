# -*- coding: utf-8 -*-

C = int(input())
for _ in range(C):
    N, M = map(int, input().split())
    print(-(-N // M))