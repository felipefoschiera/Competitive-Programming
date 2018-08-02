# -*- coding: utf-8 -*-

def msg_shift(msg, n):
    new_msg = ""
    _min, _max = 0, 0
    for c in msg:
        if c.isalpha():
            if c.islower():
                _min, _max = 97, 122 # a-z
            else:
                _min, _max = 65, 90  # A-Z
            pos = ord(c) #ord retorna a posição
            new_pos = pos + n
            if new_pos > _max:
                diff = new_pos - _max
                new_pos = _min - 1 + diff
            new_msg += chr(new_pos)
        else:
            new_msg += c
    return new_msg

while True:
    try:
        frase = input()
        print(msg_shift(frase, 13))
    except:
        break