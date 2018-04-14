import sys

meses =[31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 25]
def tempo(mes, dia):
    if mes == 12 and dia == 25:
        return "E natal!"
    if mes == 12 and dia > 25:
        return "Ja passou!"
    if mes == 12 and dia == 24:
        return "E vespera de natal!"
    # 11 24
    tempo_dias = meses[mes-1] - dia 
    
    for i in range(mes, 12):
        tempo_dias += meses[i]    
    return "Faltam {} dias para o natal!".format(tempo_dias)

for line in sys.stdin:
    mes, dia = map(int, line.split())
    print(tempo(mes, dia))
