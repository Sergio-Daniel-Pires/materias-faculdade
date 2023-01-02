lista_nome = list(input("Digite o nome dos alunos: ").split())
lista_portugues = []
lista_matematica = []
lista_fisica = []
lista_medias = []


for i in lista_nome:
    notas_portugues = lista_numeros = list(map(float, input(f"Digite as notas de portugues de {i}: ").split()))
    lista_portugues.append(notas_portugues)

for i in lista_nome:
    notas_matematica = lista_numeros = list(map(float, input(f"Digite as notas de matematica de {i}: ").split()))
    lista_matematica.append(notas_matematica)

for i in lista_nome:
    notas_fisica = lista_numeros = list(map(float, input(f"Digite as notas de fisica de {i}: ").split()))
    lista_fisica.append(notas_fisica)

lista_media_protugues = []
lista_media_matematica = []
lista_media_fisica = []

for i in range(len(lista_portugues)):
    lista_media_protugues.append(sum(lista_portugues[i])/len(lista_portugues[i]))
media_portugues = sum(lista_media_protugues)/len(lista_media_protugues)

for i in range(len(lista_matematica)):
    lista_media_matematica.append(sum(lista_matematica[i])/len(lista_matematica[i]))
media_matematica = sum(lista_media_matematica)/len(lista_media_matematica)

for i in range(len(lista_fisica)):
    lista_media_fisica.append(sum(lista_fisica[i])/len(lista_fisica[i]))
media_fisica = sum(lista_media_fisica)/len(lista_media_fisica)

print("As médias serão: ")
print(media_portugues, media_matematica, media_fisica, (media_portugues + media_matematica + media_fisica)/3)