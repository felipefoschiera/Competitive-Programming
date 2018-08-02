# -*- coding: utf-8 -*-
# Felipe G. Foschiera
# URI 1276 - Faixa de Letras
while True:
    try:
        seq = input()
        if not seq: print()
        else:
            seq = sorted(set(seq.replace(" ", "")))
            start_char = end_char = ""
            chars = []
            for c in range(len(seq)):
                if len(seq) == 1:
                    chars.append("{}:{}".format(seq[c], seq[c]))
                    break
                if c == 0:
                    start_char = seq[c]
                else:
                    if ord(seq[c]) == ord(seq[c-1]) + 1:
                        end_char = seq[c]
                        if c == len(seq) -1: chars.append("{}:{}".format(start_char, end_char))
                    else:
                        end_char = seq[c-1]
                        chars.append("{}:{}".format(start_char, end_char))
                        start_char = seq[c] 
                        if c == len(seq) - 1:chars.append("{}:{}".format(start_char, start_char))

    
            print(', '.join(chars))
    except EOFError: break
