package base;
import java.util.ArrayList;
import java.util.Collections;

public class Baralho {
	private ArrayList<Carta> vetorCartas;
	
	public Baralho() {
		vetorCartas = new ArrayList<Carta>();
	}
	
	public void adicionarCarta (Carta card) {
		if(vetorCartas.size() < 30){
			vetorCartas.add(card);
		}
	}
	
	public Carta comprarCarta() {
		return vetorCartas.remove(vetorCartas.size() - 1);
	}
	
	public void embaralhar() {
		Collections.shuffle(vetorCartas);
		int n;
		
		for(n = vetorCartas.size() - 1; n > -1; n--) {			
			System.out.println(vetorCartas.get(n));
		}
	}
}
