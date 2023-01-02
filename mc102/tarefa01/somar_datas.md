a) As entradas vão ser a data inicial e os dias a serem somados, a saida vai ser a data final. A relação entre elas vai ser um algoritimo de adição, subtração e comparação.

b)
1-Pegue a data inicial e separe em, XX/YY/ZZZZ, sendo XX os dias, YY os meses e YYYY o ano.
2-Pegue os dias a serem somados e adicione a XX
3-Paso XX de um número maior que 31 e o YY for igual a 01, 03, 05, 07, 08, 10 ou 12, subtraia 30 do XX e adicione 1 no YY.
4-Caso XX de um número maior que 31 e o YY for igual a 04, 06, 09, 11 subtraia 29 do XX e adicione 1 no YY.
4-Caso XX de um número maior que 28 e o YY for igual a 02 subtraia 27 do XX e adicione 1 no YY.
5-Caso YY de maior que 12, subtraia 11 dele, 30 do XX e adicione 1 ao YYYY.
6-Entregue a data final.
