def Pe(n, listd):
    if n <= 3:
        return n
    else:
        if n not in listd:
            pe1 = Pe(n-1, listd)
            pe2 = 2*Pe(n-2, listd)
            pe3 = 3*Pe(n-3, listd)
            pef = pe1+pe2+pe3
            listd[n] = pef
            return pef
        else:
            return listd[n]
            
def main():
    n = int(input())
    listd = {}
    print(Pe(n, listd))

main()

"""
Desculpa a falta de exercicios, me embananei com o resto das matérias.
"""