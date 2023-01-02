nmaliciosos = input()
atual = 1
maliciosos = []
while atual <= int(nmaliciosos):
    sm = input()
    maliciosos.append(sm)
    atual += 1
nsites = input()
atual = 1
cordenadas = []
while atual <= int(nsites):
    x0, y0, x1, y1, endereço = input().split()
    x0, y0, x1, y1 = [int(x0), int(y0), int(x1), int(y1)]
    cordenadas.append([x0, y0, x1, y1, endereço])
    atual += 1
atual = 0
while True:
    x, y = input().split()
    x, y = [int(x), int(y)]
    if int(x) == -1 and int(y) == -1:
        break
    for site in cordenadas:
        xi = site[0]
        yi = site[1]
        xf = site[2]
        yf = site[3]
        dominio = site[4]
        if (xi <= x <= xf) and (yi <= y <= yf):
            if dominio in maliciosos:
                print("malicioso")
                break
            else:
                print("seguro")
                break
    else:
        print("nenhum")
### Codigos para teste
# print(xi[atual], xf[atual], yi[atual], yf[atual], sites[atual])
# print(xi[atual]-1, x, xf[atual]+1, yi[atual]-1, y, yf[atual]+1)