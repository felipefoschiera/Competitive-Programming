quant_alunos = int(input())
dados = []
maior_nota = matricula = 0 
for _ in range(quant_alunos):
    num, nota = input().split()
    num, nota = int(num), float(nota)
    if nota > maior_nota:
        maior_nota = nota
        matricula = num

if maior_nota < 8.0:
    print("Minimum note not reached")
else:
    print(matricula)