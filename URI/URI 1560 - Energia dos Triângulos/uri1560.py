# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1560 - Energia dos Triângulos

from sys import stdin

class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y
        
class Triangle:
    def __init__(self, a, b, c):
        self.a, self.b, self.c = a, b, c
    def area(self):
        return abs( # Cálculo da área do triângulo
            self.a.x*(self.b.y-self.c.y) + 
            self.b.x*(self.c.y-self.a.y) + 
            self.c.x*(self.a.y-self.b.y)
        ) / 2

# O ponto 'pt' está dentro do triângulo 't' se a área do triângulo é igual a soma das áreas de triângulos
# formados pelo ponto pt no lugar de cada ponto com os pontos restantes.
def inside(pt, t): 
    at = t.area()
    a1 = Triangle(pt, t.b, t.c).area()
    a2 = Triangle(t.a, pt, t.c).area()
    a3 = Triangle(t.a, t.b, pt).area()
    return at == a1 + a2 + a3

def main():
    for line in stdin:
        N, M = map(int, line.split()) # Lemos a quant. de pontos pretos e a quant. de pontos brancos
        b, w = [], []
        for i in range(N): # Definição dos pontos pretos
            x, y = map(int, input().split()) 
            b.append(Point(x, y)) # Criamos um Ponto que contém x e y e o inserimos na lista de pontos pretos
        for i in range(M):
            x, y = map(int, input().split())
            w.append(Point(x, y)) # Criamos um Ponto que contém x e y e o inserimos na lista de pontos brancos
        ans = 0 # Energia dos triângulos
        for i in range(N): # Ponto A -  quant. de pontos pretos
            for j in range(i): # Ponto B - quant. sem repetir
                for k in range(j): # Ponto C - quant. sem repetir
                    cnt = 0 # Contagem de pontos brancos dentro do triângulo formado pelos pontos pretos i, j, k
                    for l in range(M): # Para cada ponto branco no plano
                        # Se o ponto branco l está dentro do triângulo formado
                        # pelos pontos pretos nos índices i, k  e j, incrementar um
                        cnt += inside(w[l], Triangle(b[i], b[k], b[j])) 
                    ans += cnt ** 2 # A energia do triângulo é incrementada pela quant. de pontos brancos ** 2
        print(ans)
    
if __name__ == "__main__":
    main()
