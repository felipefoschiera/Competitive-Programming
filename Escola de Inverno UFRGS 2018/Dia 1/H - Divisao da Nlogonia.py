# -*- coding: utf-8 -*-

def main():
    K = int(input())
    if K == 0:
        return
    N, M = map(int, input().split())
    for _ in range(K):
        X, Y = map(int, input().split())
        if X == N or Y == M:
            print("divisa")
        elif X > N:
            print("NE" if Y > M else "SE")
        else:
            print("NO" if Y > M else "SO")
        
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
