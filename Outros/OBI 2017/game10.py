def main():
    posicoes = int(input())
    disco = int(input())
    aviao = int(input())
    movimentos = (posicoes - aviao + disco) if aviao > disco else (disco - aviao)
    print(movimentos)

main()