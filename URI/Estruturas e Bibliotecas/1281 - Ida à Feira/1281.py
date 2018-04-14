def main():
    N = int(input())
    for _ in range(N):
        M = int(input())
        produtos = {}
        for _ in range(M):
            produto, preco = input().split()
            preco = float(preco)
            produtos[produto] = preco
        custo = 0
        P = int(input())
        for _ in range(P):
            prod, quant = input().split()
            quant = int(quant)
            custo_produto = produtos[prod] * quant
            custo += custo_produto
        print("R$ {:.2f}".format(custo))
main()