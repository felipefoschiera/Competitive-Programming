# -*- coding: utf-8
# Felipe G. Foschiera
# URI 2750 - Saída 4
print("-"*39)
print("|  decimal  |  octal  |  Hexadecimal  |")
print("-"*39)
for i in range(16):
    if i < 8:
        print("|      {}    |    {}    |       {}       |".format(i, oct(i).lstrip("0").lstrip("o"), hex(i).lstrip("0").lstrip("x").upper()))
    elif i < 10:
        print("|      {}    |   {}    |       {}       |".format(i, oct(i).lstrip("0o"), hex(i).lstrip("0x").upper()))
    else:
        print("|     {}    |   {}    |       {}       |".format(i, oct(i).lstrip("0o"), hex(i).lstrip("0x").upper()))
        
print("-"*39)
