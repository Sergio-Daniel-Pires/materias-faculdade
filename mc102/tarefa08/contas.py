class con:

    contas = []

    def modulo(numero):
        """
        Função para facilitar a utilização de numeros.
        transforma qualquer numero em seu módulo com
        duas casas decimais.
        """
        mod = (numero**2)**0.5
        mod_rnd = f"{mod:.2f}"
        return (mod_rnd)

    def ver_data(dataF, dataA):
        """
        Compara duas datas no modelo DD/MM/AAAA
        e retorna se é retroativa ou não. 
        """
        diaF, diaA = int(dataF[0:2]), int(dataA[0:2])
        mesF, mesA = int(dataF[3:5]), int(dataA[3:5])
        anoF, anoA = int(dataF[6:10]), int(dataA[6:10])
        if anoF > anoA or (anoF == anoA and (mesF > mesA or (mesF == mesA and diaF >= diaA))):
            return True
        return False

    def achar_conta(num_conta):
        """
        Acha o dicionario correspondente a uma
        conta na lista de contas.
        """
        if len(con.contas) == 0:
            return False
        for conta in con.contas:
            if conta['numero'] == str(num_conta):
                return conta
        return False

    def criar(numero_conta):
        """
        Cria um dicionario e adiciona no conjunto
        de contas.
        """
        if con.achar_conta(numero_conta) == False:
            dados = {
                'numero': numero_conta,
                'saldo': [0],
                'tipo': [""],
                'data': [""],
                'desc': [""],
            }
            con.contas.append(dados)
            print("Conta aberta com sucesso")
            return
        else:
            print("Número de conta já existe")
            return

    def saldo(num_conta):
        """
        retorna o saldo de uma conta
        """
        conta = con.achar_conta(num_conta)
        if conta == False:
            return None
        else:
            return sum(conta['saldo'])

    def op(conta, nome, var):
        """
        facilita operar o dicionario da conta
        """
        conta[nome].append(var)

    def movimentar(tipo, num_conta, valor, data, desc):
        """
        realiza transações numa conta.
        """
        conta = con.achar_conta(num_conta)
        if conta == False:
            print("Esta conta não existe")
        else:
            dataA = (conta['data'][-1])
            if len(dataA) == 0 or con.ver_data(data, conta['data'][-1]) == True:
                if tipo == 'sacar':
                    saldo_conta = con.saldo(num_conta)
                    if saldo_conta > 0 and saldo_conta >= float(valor):
                        valor = -float(valor)
                        tipo = 'Saque'
                    else:
                        print("Saldo insuficiente")
                        return
                con.op(conta, 'saldo', float(valor))
                if tipo == 'depositar':
                    tipo = "Depósito"
                con.op(conta, 'tipo', tipo)
                con.op(conta, 'data', data)
                con.op(conta, 'desc', desc)
                print(f"{tipo} realizado com sucesso")
            else:
                print("Movimentação tem data retroativa")

    def extrato(num_conta, data):
        """
        Printa todas as transações de uma conta
        """
        conta = con.achar_conta(num_conta)
        if conta == False:
            return
        else:
            for num in range(1, len(conta['saldo'])):
                if  con.ver_data(conta['data'][num], data) == True:
                    print(f"{conta['tipo'][num]} de valor R$ {con.modulo(conta['saldo'][num])} realizado em {conta['data'][num]}")
                    print(f"Descrição adicional: {conta['desc'][num]}")
                    print(f"Saldo após movimentação: R$ {con.modulo(sum(conta['saldo'][0:num+1]))}")

    def fechar_conta(numero_conta):
        """
        Deleta o dicionaro correspondente a conta
        do numero que foi passado.
        """
        if con.saldo(numero_conta) != 0:
            print("A conta não pode ser fechada")
        else:
            for num in range(len(con.contas)):
                conta = con.contas[num]
                if conta['numero'] == numero_conta:
                    del con.contas[num]
                    print("Conta fechada com sucesso")
                    return
            print("Não foi possivel localizar a conta")