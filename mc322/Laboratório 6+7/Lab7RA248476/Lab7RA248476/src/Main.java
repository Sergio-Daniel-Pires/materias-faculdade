import base.*;
import base.cartas.*;

import java.util.Random;

public class Main {

	public static void main(String[] args) {
		Mesa mesa = new Mesa();
		Baralho bP = new Baralho();
		Baralho bS = new Baralho();
		int maxLacaios = 1;
		int maxMana = 10;
		int maxAtaque = 10;
		int maxVida = 10;
		int index;
		Random gerador = new Random();
		bP.preencheAleatorio(gerador, util.Util.MAX_CARDS, maxMana, maxAtaque, maxVida);
		bS.preencheAleatorio(gerador, util.Util.MAX_CARDS, maxMana, maxAtaque, maxVida);

		for (int i = 0; i < maxLacaios; i++) {
			mesa.getLacaiosP().add(util.Util.geraCartaAleatoria(gerador, maxMana, maxAtaque, maxVida, TipoCarta.LACAIO));
			mesa.getLacaiosS().add(util.Util.geraCartaAleatoria(gerador, maxMana, maxAtaque, maxVida, TipoCarta.LACAIO));
		}

		for (int i = 0; i < util.Util.MAO_INI; i++) {
			mesa.getMaoP().add(bP.comprar());
			mesa.getMaoS().add(bS.comprar());
		}
		mesa.getMaoS().add(bS.comprar());

		Jogada jP = new Jogada(mesa.sacarCarta('P'), null, 'P');
		ProcessadorJogada.processar(jP, mesa);
		Jogada jS = new Jogada(mesa.sacarCarta('S'), null, 'S');
		ProcessadorJogada.processar(jS, mesa);

		System.out.printf("\n Jogadas com lacaios:\n");

		index = gerador.nextInt(mesa.getLacaiosS().size());
		jP = new Jogada(mesa.sacarCarta('P'), mesa.getLacaiosS().get(index), 'P');
		ProcessadorJogada.processar(jP, mesa);
		if (!mesa.getLacaiosP().isEmpty()) {
			index = gerador.nextInt(mesa.getLacaiosP().size());
			jS = new Jogada(mesa.sacarCarta('S'), mesa.getLacaiosP().get(index), 'S');
			ProcessadorJogada.processar(jS, mesa);
		}

	}

}
