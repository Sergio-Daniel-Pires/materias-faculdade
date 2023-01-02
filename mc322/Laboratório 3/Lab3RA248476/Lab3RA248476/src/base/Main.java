package base;
import static util.Util.*;

import util.Util;

public class Main {

	public static void main(String[] args) {
		CartaLacaio lac1 = new CartaLacaio(1, "Murloc", 1, 1, 1);
		CartaLacaio lac2 = new CartaLacaio(2, "Alcolito da dor", 2, 2, 2);
		CartaLacaio lac3 = new CartaLacaio(3, "O Litch rei", 10, 10, 10);
		
		Baralho magic = new Baralho();
		magic.adicionarCarta(lac1);
		magic.adicionarCarta(lac2);
		magic.adicionarCarta(lac3);
		
		//magic.embaralhar();
		
		CartaLacaio lac4 = new CartaLacaio(4, "Anduin o arauto da luz", 1, 1, 1);
		CartaLacaio lac5 = new CartaLacaio(5, "Jaina Proudmore", 2, 2, 2);
		CartaLacaio lac6 = new CartaLacaio(6, "Calafrante", 3, 3, 3);
		
		BaralhoArrayList arrayMagic = new BaralhoArrayList();
		arrayMagic.adicionarCarta(lac4);
		arrayMagic.adicionarCarta(lac5);
		arrayMagic.adicionarCarta(lac6);
		
		arrayMagic.embaralhar();
		arrayMagic.embaralhar();
		arrayMagic.embaralhar();
		
		CartaLacaio comprada = arrayMagic.comprarCarta();
		System.out.println("A carta comprada foi:\n" + comprada);
		
		System.out.println("Embaralhando novamente temos:");
		arrayMagic.embaralhar();
		
		CartaLacaio sob1 = arrayMagic.comprarCarta();
		CartaLacaio sob2 = arrayMagic.comprarCarta();
		System.out.println("E buffando temos:");
		Util.buffar(sob1, 10);
		Util.buffar(sob2, 20, 30);
		System.out.println(sob1);
		System.out.println(sob2);
		
	}

}
