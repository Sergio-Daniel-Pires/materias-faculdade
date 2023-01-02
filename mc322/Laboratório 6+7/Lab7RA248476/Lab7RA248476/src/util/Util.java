package util;
import java.util.Random;

import util.RandomStringGen;
import base.cartas.Lacaio;
import base.cartas.Carta;
import base.cartas.HabilidadesLacaio;
import base.cartas.TipoCarta;
import base.cartas.magias.*;

public class Util {
	public static final int PODER_HEROI = 1;
	
	public static void buffar(Lacaio lac, int a) {
		if (a > 0) {
			lac.setVidaMaxima(lac.getVidaMaxima() + a);
			lac.setVidaAtual(lac.getVidaAtual() + a);
			lac.setAtaque(lac.getAtaque() + a);
			alteraNomeFortalecido(lac);
		}
	}
	public static void buffar(Lacaio lac, int a, int v) {
		if (a > 0 && v > 0) {
			lac.setVidaMaxima(lac.getVidaMaxima() + v);
			lac.setVidaAtual(lac.getVidaAtual() + v);
			lac.setAtaque(lac.getAtaque() + a);
			alteraNomeFortalecido(lac);
		}
	}
	private static void alteraNomeFortalecido(Lacaio lac) {
		lac.setNome(lac.getNome() + " Buffed");
	}
	
	public static final int MAX_CARDS = 30;
	public static final int MAO_INI = 3;
	
	public static int randInt(Random gerador, int min, int max) {
		return gerador.nextInt((max - min) + 1) + min;
	}
	
	public static Carta geraCartaAleatoria(Random gerador, int maxMana, int maxAtaque, int maxVida, TipoCarta tc) {
		RandomStringGen geradorString = new RandomStringGen(4);
		String cardNome = geradorString.nextString();
		int cardMana = randInt(gerador, 1, maxMana);
		int cardAtaque = randInt(gerador, 1, maxAtaque);
		int cardVida = randInt(gerador, 1, maxVida);
		TipoCarta cardTipo;
		HabilidadesLacaio cardHabilidade;
		// verifica se o tipo do card é nulo
		if(tc == null) {
			int numTipo = randInt(gerador, 0, 3);
			TipoCarta[]tipos = TipoCarta.values();
			cardTipo = tipos[numTipo];
		}
		else {
			cardTipo = tc;
		}
		
		Carta cardNovo = null;
		
		if(cardTipo == TipoCarta.LACAIO) {
			// gera habilidade e vida aleatoriamente, se for lacaio
			int numHabilidade = randInt(gerador, 0, 2);
			HabilidadesLacaio[]habilidades = HabilidadesLacaio.values();
			cardHabilidade = habilidades[numHabilidade];
			
			cardNovo = new Lacaio(cardNome, cardMana, cardAtaque, cardVida, cardHabilidade);
		}
		else {
			if(cardTipo == TipoCarta.BUFF) {
				cardNovo = new Buff(cardNome, cardMana, cardAtaque, cardVida);
			}
			else if(cardTipo == TipoCarta.DANO) {
				cardNovo = new Dano(cardNome, cardMana, cardAtaque);
			}
			else if(cardTipo == TipoCarta.DANO_AREA) {
				cardNovo = new DanoArea(cardNome, cardMana, cardAtaque);
			}
			
		}
		
		return cardNovo;
	}
	
	
}
