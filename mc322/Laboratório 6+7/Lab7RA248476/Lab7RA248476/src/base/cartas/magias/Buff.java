package base.cartas.magias;
import base.cartas.Carta;
import base.cartas.Lacaio;
import java.util.UUID;

public class Buff extends Magia{
	
	int aumentoEmAtaque;
	int aumentoEmVida;
	
	public Buff(String nome, int custoMana, int aumentoEmAtaque, int aumentoEmVida) {
		super(nome, custoMana);
		this.aumentoEmAtaque = aumentoEmAtaque;
		this.aumentoEmVida = aumentoEmVida;
	}
	
	public Buff(UUID id, String nome, int custoMana, int aumentoEmAtaque, int aumentoEmVida) {
		super(id, nome, custoMana);
		this.aumentoEmAtaque = aumentoEmAtaque;
		this.aumentoEmVida = aumentoEmVida;
	}

	@Override
	public String toString() {
		String out = super.toString();
		out +=  "Buff no ataque = "+getAumentoEmAtaque()+"\n";
		out +=  "Buff na vida = "+getAumentoEmVida()+"\n";
		return out;
	}
	
	// Gets e sets
	public int getAumentoEmAtaque() {
		return aumentoEmAtaque;
	}
	public void setAumentoEmAtaque(int aumentoEmAtaque) {
		this.aumentoEmAtaque = aumentoEmAtaque;
	}

	public int getAumentoEmVida() {
		return aumentoEmVida;
	}
	public void setAumentoEmVida(int aumentoEmVida) {
		this.aumentoEmVida = aumentoEmVida;
	}
	
	public void usar(Carta card) {
		Lacaio alvo = (Lacaio) card;
		int alvoVidaAtual = alvo.getVidaAtual();
		int alvoVidaMaxima = alvo.getVidaMaxima();
		int alvoAtaque = alvo.getAtaque();
		
		alvo.setVidaAtual(alvoVidaAtual + this.aumentoEmVida);
		alvo.setVidaMaxima(alvoVidaMaxima + this.aumentoEmVida);
		alvo.setAtaque(alvoAtaque + this.aumentoEmAtaque);
	}
}
