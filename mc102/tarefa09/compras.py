def comparar(dem, dis):
    demloc = 0
    disloc = 0
    faltantes = []
    Boolean = True
    while Boolean == True:
        if len(dis) == disloc or len(dem) == demloc:
            for i in dem[demloc:(len(dem))]:
                faltantes.append(str(i))
            Boolean = False
            return faltantes
        if dem[demloc] == dis[disloc]:
            demloc += 1
            disloc += 1
        elif dem[demloc] > dis[disloc]:
            disloc += 1
        elif dem[demloc] < dis[disloc]:
            faltantes.append(str(dem[demloc]))
            demloc += 1
        else:
            break
    return faltantes

def main():
    demanda = input().split()
    disponivel = input().split()
    demf = list(map(int, demanda))
    demf.sort()
    disf = list(map(int, disponivel))
    disf.sort()
    faltantes = comparar(demf, disf)
    print(" ".join(faltantes))


main()