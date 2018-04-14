# -*- coding: utf-8 -*-
# Felipe Gazzoni Foschiera
# URI 2158 - Ajudando o Tio Cláudio

i = 1
while True:
    try:
        fp, fh = map(int, input().split())
        total_faces = fp + fh
        arestas = (fp * 5 + fh * 6) // 2 # Arestas = Ligacoes
        # F + V = A + 2 - Faces + Vertices = Arestas + 2
        # Atomos = Vertices
        V = arestas + 2 - total_faces
        print("Molecula #{}.:.".format(i)) 
        i += 1
        print("Possui {} atomos e {} ligacoes".format(V, arestas))
        print()
    except EOFError:
        break