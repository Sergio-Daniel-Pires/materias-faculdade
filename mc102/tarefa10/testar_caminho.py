import sys


def check_caminho(in_file_name, out_file_name):
    mat = []
    with open(in_file_name) as f:
        for linha in f:
            mat.append(list(linha.strip()))
    m = len(mat)
    n = len(mat[0])

    with open(out_file_name) as f:
        i1, j1 = -1, -1
        for linha in f:
            linha = linha.strip()
            try:
                i2, j2 = map(int, linha.split(maxsplit=1))
            except Exception as e:
                assert False, f"linha '{linha}' inválida, deveria conter dois números: {e}"
            assert 0 <= i2 < m and 0 <= j2 < n, f"posição {i2} {j2} está fora do labirinto"
            if i1 == -1 and j1 == -1:
                assert mat[i2][j2] == "E", "o caminho não inicia na origem"
            else:
                assert abs(i2 - i1) + abs(j2 - j1) == 1, f"passo {i1} {j1} -> {i2} {j2} inválido"
                assert mat[i2][j2] != "#", f"posição {i2} {j2} é um obstáculo"
            i1, j1 = i2, j2
        assert mat[i1][j1] == "S", "o caminho não termina na saída"


def main():
    if len(sys.argv) != 3:
        print("uso:   python3 testar_caminho.py <labirinto_entrada.in> <caminho_saida.out>")
        return
    in_file_name = sys.argv[1]  # Nome do arquivo .in contendo o labirinto
    out_file_name = sys.argv[2]  # Nome do arquivo .out contendo o caminho
    check_caminho(in_file_name, out_file_name)
    print("o caminho é válido")


if __name__ == "__main__":
    main()
