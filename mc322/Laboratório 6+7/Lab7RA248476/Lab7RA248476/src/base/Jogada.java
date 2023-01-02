package base;
import base.cartas.*;

public class Jogada {
	private Carta jogada;
	private Carta alvo;
	private char autor;
	
	public Jogada(Carta jogada, Carta alvo, char autor){
		// char == 'P' significa Primeiro jogador
		// char == 'S' significa Primeiro jogador
		this.jogada = jogada;
		this.autor = autor;
		this.alvo = alvo;
	}
	
	// Gets e sets
	
	public Carta getJogada() {
		return this.jogada;
	}
	public void setJogada(Carta jogada) {
		this.jogada = jogada;
	}
	
	public Carta getAlvo() {
		return this.alvo;
	}
	public void setAlvo(Carta alvo) {
		this.alvo = alvo;
	}
	
	public char getAutor() {
		return this.autor;
	}
	public void setAutor(char autor) {
		this.autor = autor;
	}
	
	@Override
	public String toString() {
		String out = "";
		if(autor == 'P') {
			out += "O primeiro jogador ";
		}else {
			out += "O segundo jogador ";
		}
		out += "jogou " + this.jogada + " ";
		if(this.alvo == null) {
			out += "no heroi adversario";
		}else {
			out += "no " + this.alvo;
		}
		return out;
	}
}
