package base.cartas.magias;
import java.util.UUID;

import base.cartas.Carta;
import base.cartas.Lacaio;

public class Dano extends Magia{
	private int dano;
	
	public Dano(String nome, int custoMana, int dano) {
		super(nome, custoMana);
		this.dano = dano;
	}
	
	public Dano(UUID id, String nome, int custoMana, int dano) {
		super(id, nome, custoMana);
		this.dano = dano;
	}
	
	// Gets e sets
	public int getDano() {
		return this.dano;
	}
	public void setDano(int dano) {
		this.dano = dano;
	}
	
	@Override
	public String toString() {
		String out = super.toString();
		out +=  "Dano no alvo = "+getDano()+"\n";
		return out;
	}
	
	public void usar(Carta card) {
		Lacaio alvo = (Lacaio) card;
		int alvoVidaAtual = alvo.getVidaAtual();
		alvo.setVidaAtual(alvoVidaAtual - this.dano);
	}
}
