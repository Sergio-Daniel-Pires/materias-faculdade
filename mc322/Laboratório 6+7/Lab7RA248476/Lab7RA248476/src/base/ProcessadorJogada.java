package base;

import java.util.ArrayList;

import base.cartas.*;
import base.cartas.magias.*;

public class ProcessadorJogada {
	
	public ProcessadorJogada(){
		
	}
	
	public static void processar(Jogada jogada, Mesa mesa){
		// Variaveis da mesa
		ArrayList<Carta> maoP = mesa.getMaoP();
		ArrayList<Carta> maoS = mesa.getMaoS();
		ArrayList<Carta> lacaiosP = mesa.getLacaiosP();
		ArrayList<Carta> lacaiosS = mesa.getLacaiosS();
		int poderHeroiP = mesa.getPoderHeroiP();
		int poderHeroiS = mesa.getPoderHeroiS();
		
		// Variaveis de auxilio
		Carta card = jogada.getJogada();
		Carta alvo = jogada.getAlvo();
		int manaGasta = card.getCustoMana();
		char autor = jogada.getAutor();
		
		// Variaveis para Print
		String autorString;
		String alvoString;
		int poderHeroico;
		
		
		if(alvo == null) {
			alvoString = "Heroi inimigo";
		}else {
			alvoString = alvo.toString();
		}
		
		// Pega valores do adversario
		ArrayList<Carta> lacaiosInimigos = null;
		ArrayList<Carta> lacaiosAliados = null;
		if(autor == 'P') {
			lacaiosAliados = lacaiosP;
			lacaiosInimigos = lacaiosS;
			autorString = "Primeiro jogador:";
			poderHeroico = poderHeroiS;
		}else {
			lacaiosAliados = lacaiosS;
			lacaiosInimigos = lacaiosP;
			autorString = "Segundo jogador:";
			poderHeroico = poderHeroiP;
		}
		
		// 0. Prints de log
		System.out.println("O " + autorString);
		System.out.println("Jogou " + card);
		System.out.println("Contra " + alvoString);
		System.out.println("Na mesa tem (" + lacaiosInimigos.size() + ") inimigos");
		System.out.println("Sendo eles: " + lacaiosInimigos);
		System.out.println("Poder heroico do adversario: " + poderHeroico);
		System.out.println("=-=-=-=-=-=-=-=-=-=-=-=");
		
		// 1. Decrementa mana
		mesa.decMana(manaGasta, autor);
		int manaP = mesa.getManaP();
		int manaS = mesa.getManaS();
		
		// 2. Verifica tipo
		if(card instanceof Lacaio) {
			HabilidadesLacaio cardHab = ((Lacaio) card).getHabilidade();
			if(cardHab == HabilidadesLacaio.INVESTIDA) {
				if (alvo != null) {					
					card.usar(alvo);
				}else {
					poderHeroico -= ((Lacaio) card).getAtaque();
				}
			}
			lacaiosAliados.add(card);
		}
		else {
			if(card instanceof Buff) {
				if(alvo instanceof Lacaio) {
					card.usar(alvo);
				}
			}
			else if(card instanceof Dano) {
				Carta provocar = null;
				for(int numLac = 0; numLac < lacaiosInimigos.size(); numLac++) {
					Carta lacInimigo = lacaiosInimigos.get(numLac);
					HabilidadesLacaio lacHab = ((Lacaio) lacInimigo).getHabilidade();
					if(lacHab == HabilidadesLacaio.PROVOCAR)
						provocar = lacInimigo;
				}
				if(provocar == null) {
					card.usar(null);
				}else {
					card.usar(provocar);
				}
			}
			else if(card instanceof DanoArea) {
				for(int numLac = 0; numLac < lacaiosInimigos.size(); numLac++) {
					Carta lacInimigo = lacaiosInimigos.get(numLac);
					card.usar(lacInimigo);
				}
				if(autor == 'P') {
					poderHeroiS -= ((DanoArea) card).getDano();
				}else {
					poderHeroiP -= ((DanoArea) card).getDano();
				}
			}
		}
		
		// 2.5 limpar lacaios mortos
		for(int numLac = 0; numLac < lacaiosP.size(); numLac++) {
			Carta lac = lacaiosP.get(numLac);
			if(((Lacaio) lac).getVidaAtual() < 1)
				lacaiosP.remove(lac);
		}
		for(int numLac = 0; numLac < lacaiosS.size(); numLac++) {
			Carta lac = lacaiosS.get(numLac);
			if(((Lacaio) lac).getVidaAtual() < 1)
				lacaiosS.remove(lac);
		}
		System.out.println("Na mesa tem (" + lacaiosInimigos.size() + ") inimigos");
		System.out.println("Sendo eles: " + lacaiosInimigos);
		System.out.println("Poder heroico do adversario: " + poderHeroico);
		System.out.println();
		
		// 3. Atualizar mesa
		mesa = new Mesa(maoP, maoS, lacaiosP, lacaiosS, poderHeroiP, poderHeroiS, manaP, manaS);
	
		// 4. Printar dnv os ultimos, ja vejo
	}
}
