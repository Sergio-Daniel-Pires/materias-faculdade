from contas import con


def main():
    """
    Requisita uma ação do úsuario, manda as informações
    passadas pelo usuario para um outro módulo (contas.py)
    retorna um status e volta para receber outra ação.
    """
    while True:
        acao = input()
        if acao == 'abrir':
            num_conta = input()
            con.criar(num_conta)
        elif acao in ['depositar', 'sacar']:
            informacoes = input()
            num_conta, valor, data, descricao = informacoes.split(maxsplit=3)
            con.movimentar(acao, num_conta, valor, data, descricao)
        elif acao in 'saldo':
            num_conta = input()
            saldo_conta = con.saldo(num_conta)
            if saldo_conta == None:
                print("Esta conta não existe")
            else:
                print(f"O saldo da conta é R$ {saldo_conta:.2f}")
        elif acao in 'extrato':
            num_conta, data = input().split()
            con.extrato(num_conta, data)
        elif acao == 'fechar':
            num_conta = input()
            con.fechar_conta(num_conta)
        elif acao == 'sair':
            break
            
main()
