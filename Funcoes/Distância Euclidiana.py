'''
Distância entre dois pontos bidimensionais A e B
     ________________________
    √(Px - Qx)² + (Py - Qy)²
'''
def distancia_euclidiana(xA, yA, xB, yB):
    return ((xA - xB) ** 2 + (yA - yB) ** 2) ** 0.5

'''
Também pode-se utilizar um objeto Ponto
'''
class Ponto:
    def __init__(self, x, y):
        self.x, self.y = x, y

def distancia(pontoA, pontoB):
    return ((pontoA.x - pontoB.x) ** 2 + (pontoA.y - pontoB.y) ** 2) ** 0.5

 