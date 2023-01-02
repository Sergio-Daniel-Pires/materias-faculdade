import modulo_analise as ma


def teste_01_ordena():
    lista = [2, 3, 1, 4, 1.45, 99, -234, 8, 1, -1, 3.14159]
    em_ordem = [-234, -1, 1, 1, 1.45, 2, 3, 3.14159, 4, 8, 99]
    ma.ordena(lista, False)
    assert lista == em_ordem, "A lista não foi ordenada corretamente."


def teste_02_moda():
    lista = ["a", "b", "c", "b", "c", "a", "a", "b"]
    moda = ma.moda(lista)
    assert moda == "a", "Moda incorreta."


def teste_03_mediana():
    valores = [2.2, 1.25, 8.43, 90, 200.4563, 6.5, 7.5, 5.5]
    mediana = ma.mediana(valores)
    assert mediana == 7.5, "Mediana incorreta."


def teste_04_media():
    valores = [2.2, 1.25, 8.43, 90, 200.4563, 6.5, 7.5, 5.5]
    media = ma.media(valores)
    assert media == 40.2295375, "Média incorreta."


def teste_05_media_ponderada():
    valores = [2.2, 1.25, 8.43, 90, 200.4563, 6.5, 7.5, 5.5]
    pesos = [2, 66, 4, 3, 0.096, 9, 1, 0.98]
    media_ponderada = ma.media_ponderada(valores, pesos)
    assert media_ponderada == 5.591033561039081, "Média ponderada incorreta."


def teste_06_filtrar_entre():
    valores = [2.2, 1.25, -8.43, 90, 200.4563, -6.5, 7.5, 5.5]
    filtrado = ma.filtrar_entre(valores, 2.2, 90)
    assert filtrado == [2.2, 7.5, 5.5], "A lista não foi filtrada corretamente."


def teste_07_filtrar_caracteristica():
    lista = ["Brasil", "Alemanha", "Angola", "Portugal"]
    caracteristica = ["América do Sul", "Europa", "África", "Europa"]
    filtrado = ma.filtrar_caracteristica(lista, caracteristica, "Europa")
    assert filtrado == ["Alemanha", "Portugal"], "A lista não foi filtrada corretamente."


def teste_08_histograma():
    valores = [9.9, 56.5, -9, 16.5, 21, 11, -3, 31, 21, -100, 46, 20.2, 20.19, 26, 55.111, 31.5]
    intervalos = [-18, -5, 10, 20.2, 31.5, 45.9]
    histograma = ma.histograma(valores, intervalos)
    assert histograma == [1, 2, 3, 5, 1], "O histograma não foi encontrado corretamente."


def teste_09_maiores_k():
    valores = [2.2, 1.25, -8.43, 90, 200.4563, -6.5, 7.5, 5.5]
    maiores = ma.maiores_k(valores, 4)
    assert maiores == [200.4563, 90, 7.5, 5.5], "Maiores incorretos."


def teste_10_menores_k():
    valores = [2.2, 1.25, -8.43, 90, 200.4563, -6.5, 7.5, 5.5]
    menores = ma.menores_k(valores, 4)
    assert menores == [-8.43, -6.5, 1.25, 2.2], "Menores incorretos."


def teste_11_remove_duplicatas():
    lista = ["b", "a", "c", "a", "c", "b", "b", "a"]
    sem_dup = ma.remove_duplicatas(lista)
    assert sem_dup == ["b", "a", "c"], "As duplicatas não foram removidas corretamente."
