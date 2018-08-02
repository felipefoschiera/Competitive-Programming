# -*- coding: utf-8 -*-

def msg_shift(msg, n):
    new_msg = ""
    _min, _max = 65, 90
    for c in msg:
        pos = ord(c)
        new_pos = pos - n 
        if new_pos < _min:
            diff = _min - new_pos
            new_pos = _max + 1 - diff
        elif new_pos > _max:
            diff = new_msg - _max
            new_pos = _min - 1 + diff
        new_msg += chr(new_pos)
    return new_msg

quant = int(input())
for _ in range(quant):
    string = input()
    shift = int(input())
    print(msg_shift(string, shift))
