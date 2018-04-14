bolas = list((map(int, input().split())))

resto = sum(bolas) % 9

renas = {
    1: 'Dasher',
    2: 'Dancer', 
    3: 'Prancer', 
    4: 'Vixen',
    5: 'Comet',
    6: 'Cupid', 
    7: 'Donner',
    8: 'Blitzen',
    0: 'Rudolph'
}
print(renas[resto])    
