xip, yip, xfp, yfp = input().split()
xip, yip, xfp, yfp = [int(xip), int(yip), int(xfp), int(yfp)]
entradas = input()
atual = 1
fechar = 0
while atual <= int(entradas):
    x0, y0, x1, y1 = input().split()
    x0, y0, x1, y1 = [int(x0), int(y0), int(x1), int(y1)]
    if yip < y0 < yfp and xip < x0 < xfp:
        atual += 1
        fechar += 1
    elif not (x1 <= xip or x0 >= xfp or y1 <= yip or y0 >= yfp):
        fechar += 1
        atual += 1
    else:
        atual += 1  
print("Devem ser fechados " + str(fechar) + " anúncios")