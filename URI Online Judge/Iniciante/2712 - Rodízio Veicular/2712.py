def restricao(placa):
    if len(placa) != 8:
        return 'FAILURE'
    for letra in placa[:3]:
        if letra.islower() or not letra.isalpha():
            return 'FAILURE'
    if placa[3] != '-':
        return 'FAILURE'
    for dig in placa[4:]:
        if not dig.isdigit():
            return 'FAILURE'
    last_digit = placa[-1]
    if last_digit == '1' or last_digit == '2':
        return 'MONDAY'
    if last_digit == '3' or last_digit == '4':
        return 'TUESDAY'
    if last_digit == '5' or last_digit == '6':
        return 'WEDNESDAY'
    if last_digit == '7' or last_digit == '8':
        return 'THURSDAY'
    if last_digit == '9' or last_digit == '0':
        return 'FRIDAY'
    return 'FAILURE'
        
test_cases = int(input())
for _ in range(test_cases):
    placa = input()
    print(restricao(placa))