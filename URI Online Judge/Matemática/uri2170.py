from sys import stdin
count = 0
for line in stdin:
    a, b = map(float, line.split())
    percentual = (b * 100) / a - 100
    count += 1
    print("Projeto {}:".format(count))
    print("Percentual dos juros da aplicacao: {:.2f} %".format(percentual))
    print()