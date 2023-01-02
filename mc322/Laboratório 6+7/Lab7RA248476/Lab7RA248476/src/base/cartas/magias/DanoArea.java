package base.cartas.magias;
import base.cartas.magias.Dano;
import java.util.List;
import java.util.UUID;

import base.cartas.Carta;

public class DanoArea extends Dano{
	
	public DanoArea(String nome, int custoMana, int dano) {
		super(nome, custoMana, dano);
	}
	
	public DanoArea(UUID id, String nome, int custoMana, int dano) {
		super(id, nome, custoMana, dano);
	}
	
	@Override
	public String toString() {
		String out = super.toString();
		out +=  "Dano na area = "+getDano()+"\n";
		return out;
	}
	
	public void usar(List<Carta> listaCarta) {
		for(Carta card:listaCarta) {
			usar(card);
		}
	}
}
