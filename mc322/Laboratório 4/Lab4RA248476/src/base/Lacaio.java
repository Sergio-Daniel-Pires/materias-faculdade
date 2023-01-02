package base;

import java.util.UUID;

public class Lacaio extends Carta{
	private int ataque;
	private int vidaAtual;
	private int vidaMaxima;
	
	public Lacaio(String nome, int custoMana, int ataque, int vida) {
		super(nome, custoMana);
		this.ataque = ataque;
		this.vidaAtual = vida;
		this.vidaMaxima = vida;
	}
	
	public Lacaio(String nome, int mana) {
		super(nome, mana);
	}
	
	public Lacaio(Lacaio origem) {
		super(origem.getNome(), origem.getCustoMana());
		this.ataque = origem.getAtaque();
		this.vidaAtual = origem.getVidaAtual();
		this.vidaMaxima = origem.getVidaMaxima();
	}
	
	public String toString() {
		String out = super.toString();
		out +=  "Ataque = "+getAtaque()+"\n";
		out +=  "Vida atual = "+getVidaAtual()+"\n";
		out +=  "Vida Maxima = "+getVidaMaxima()+"\n";
		return out;
	}
	
	// Metodos Ataque
	public int getAtaque() {
		return ataque;
	}
	public void setAtaque(int ataque) {
		this.ataque = ataque;
	}
	
	// Metodos da vida atual
	public int getVidaAtual() {
		return vidaAtual;
	}
	public void setVidaAtual(int vidaAtual) {
		this.vidaAtual = vidaAtual;
	}
	
	// Metodos da vida maxima
	public int getVidaMaxima() {
		return vidaMaxima;
	}
	public void setVidaMaxima(int vidaMax) {
		this.vidaMaxima = vidaMax;
	}
	
	// Override
	public void usar(Carta alvo){
		Lacaio aux = (Lacaio) alvo;
		aux.setVidaAtual(aux.getVidaAtual() - getAtaque());
	}
	
}
