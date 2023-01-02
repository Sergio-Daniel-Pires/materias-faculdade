import base.*;

public class Main {

	public static void main(String[] args) {
		Baralho deckboladao = new Baralho();
		Lacaio lac1 = new Lacaio("Murloc", 1, 1, 1);
		Lacaio lac2 = new Lacaio("Alcolito da dor", 2, 2, 2);
		Lacaio lac3 = new Lacaio("O Litch rei", 10, 10, 10);
		
		lac1.usar(lac3);
		
		Magia mag1 = new Magia("Polimorfia", 4, "Transforma um lacaio adversio em uma ovelha 1 atk 1 def");
		
		deckboladao.adicionarCarta(lac1);
		deckboladao.adicionarCarta(lac2);
		deckboladao.adicionarCarta(lac3);
		deckboladao.adicionarCarta(mag1);
		
		deckboladao.embaralhar();
	}

}
