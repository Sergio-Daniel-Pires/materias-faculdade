package base;
import java.util.ArrayList;
import java.util.Collections;

public class BaralhoArrayList {
	private ArrayList<CartaLacaio> vetorCartas;
	
	public BaralhoArrayList() {
		vetorCartas = new ArrayList<CartaLacaio>();
	}
	
	public void adicionarCarta (CartaLacaio card) {
		if(vetorCartas.size() < 30){
			vetorCartas.add(card);
		}
	}
	
	public CartaLacaio comprarCarta() {
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
