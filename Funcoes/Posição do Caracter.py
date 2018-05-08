from string import ascii_letters

# Posição do caracter é sua posição na tabela - posição de 'a'


def pos_char(char):
    return ord(char) - ord('a')

# Também pode-se importar ascii_letters, ascii_lowercase ou ascii_uppercase


def pos(char):
    return ascii_letters.find(char)
