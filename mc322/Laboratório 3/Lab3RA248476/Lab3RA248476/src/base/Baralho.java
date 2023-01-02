package base;
import java.util.Random;

public class Baralho {
	CartaLacaio[] vetorCartas;
	int nCartas;
	static Random gerador = new Random();


	public Baralho() {
		vetorCartas = new CartaLacaio[10];
		nCartas = 0;
	}
	
	public void adicionarCarta (CartaLacaio card) {
		if(nCartas < util.Util.MAX_CARDS){
			vetorCartas[nCartas] = card;
			nCartas++;			
		}
	}
	
	public CartaLacaio comprarCarta() {
		nCartas--;
		return vetorCartas[nCartas];
	}
	
	public void embaralhar() {
		int i, j;
		
		for(i = 1; i < nCartas; i++) {
			j = gerador.nextInt(i+1);  // Sorteia um numero entre [0,i]
		 		if (j != i) {
		 			CartaLacaio a = vetorCartas[i];
		 			CartaLacaio b = vetorCartas[j];
		 			vetorCartas[i] = b;
		 			vetorCartas[j] = a;
		 		}
		 }
		// Collections.shuffle(vetorCartas);
		
		int n;
		
		for(n = nCartas - 1; n > -1; n--) {
			CartaLacaio carta = vetorCartas[n];
			System.out.println(carta);
		}
	}
}