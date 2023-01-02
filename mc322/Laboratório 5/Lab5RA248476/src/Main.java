import base.*;
import java.util.ArrayList;
import java.util.LinkedList;
import base.RandomStringGen;

public class Main {

	public static void main(String[] args) {
		Baralho deckboladao = new Baralho();
		Baralho deckquasebolado = new Baralho();
		Lacaio lac1 = new Lacaio("Murloc", 1, 1, 1);
		Lacaio lac2 = new Lacaio("Alcolito da dor", 2, 2, 2);
		Lacaio lac3 = new Lacaio("O Litch rei", 10, 10, 10);
		RandomStringGen gerador = new RandomStringGen(4);
				
		Magia mag1 = new Magia("Polimorfia", 4, "Transforma um lacaio adversio em uma ovelha 1 atk 1 def");
		
		deckboladao.adicionarCarta(lac1);
		deckboladao.adicionarCarta(lac1);
		//deckboladao.adicionarCarta(lac2);
		//deckboladao.adicionarCarta(lac3);
		deckboladao.adicionarCarta(mag1);

		deckquasebolado.adicionarCarta(lac1);
		deckquasebolado.adicionarCarta(lac2);
		deckquasebolado.adicionarCarta(lac3);
		deckquasebolado.adicionarCarta(mag1);
		
		System.out.println(deckboladao.equals(deckquasebolado));
		
		// Preparacao das listas
		ArrayList<Carta> ListCartas = new ArrayList<Carta>();
		LinkedList<Carta> LinkedCartas = new LinkedList<Carta>();
		Carta atual;
		for (int i = 0; i < 10000; i++) {
			ListCartas.add(new Lacaio(gerador.nextString() , 1, 1, 1));
			LinkedCartas.add(new Lacaio(gerador.nextString(), 1, 1, 1));
		}
		
		// Atividade 1
		long atv1 = System.nanoTime();
		for (int i = 0; i < 10000; i++) {
			ListCartas.get(i);
		}
		System.out.println("A operacao demorou " + (System.nanoTime() - atv1) / 1000000 + " ms");
	
		// Atividade 2
		long atv2 = System.nanoTime();
		for (int i = 0; i < 10000; i++) {
			LinkedCartas.get(i);
		}
		System.out.println("A operacao demorou " + (System.nanoTime() - atv2) / 1000000 + " ms");
		
		// Atividade 3
		long atv3 = System.nanoTime();
		for (int i = 0; i < 10000; i++) {
			atual = ListCartas.get(i);
			ListCartas.contains(atual);
		}
		System.out.println("A operacao demorou " + (System.nanoTime() - atv3) / 1000000 + " ms");
		
		// Atividade 4
		long atv4 = System.nanoTime();
		for (int i = 0; i < 10000; i++) {
			atual = LinkedCartas.get(i);
			LinkedCartas.contains(atual);
		}
		System.out.println("A operacao demorou " + (System.nanoTime() - atv4) / 1000000 + " ms");
		
		// Atividade 5
		// Sim, pq uma lista precisa levar em conta a posição a do elemento, logo, repeticoes precisam aparecer
	}

}
