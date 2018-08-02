tests = int(input())
for _ in range(tests):
    casas = int(input())
    graos = (2 ** casas) - 1
    peso = graos / 12 
    peso = int(peso / 1000)
    print(peso, 'kg')