quant_alunos = int(input())
dados = []
for _ in range(quant_alunos):
    info = input().split()
    numero = int(info[0])
    nota = float(info[1])
    dados.append([numero, nota])

maior_nota = 0
matricula_aluno = 0
for aluno in dados:
    if aluno[1] > maior_nota:
        maior_nota = aluno[1]
        matricula_aluno = aluno[0]

if maior_nota < 8.0:
    print("Minimum note not reached")
else:
    print(matricula_aluno)