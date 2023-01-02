package lab1;

public class CartaLacaio {
	private int ID;
	private String nome;
	private int ataque;
	private int vidaAtual;
	private int vidaMaxima;
	private int custoMana;
	
	public CartaLacaio(int ID, String nome, int ataque, int vida, int mana) {
		this.ID = ID;
		this.nome = nome;
		this.vidaAtual = vida;
		this.vidaMaxima = vida;
		this.custoMana = mana;
	}
	
	@Override
	public String toString() {
		String out = getNome() + " (ID: "+getID()+")\n";
		out +=  "Ataque = "+getAtaque()+"\n";
		out +=  "Vida atual = "+getVidaAtual()+"\n";
		out +=  "Vida Maxima = "+getVidaMaxima()+"\n";
		out +=  "Custo de Mana = "+getCustoMana()+"\n";
		return out;
	}
	
	// Metodos ID
	public int getID() {
		return ID;
	}
	public void setID(int ID) {
		this.ID = ID;
	}
	
	// Metodos Nome
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
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
	
	public int getCustoMana() {
		return custoMana;
	}
	public void setCustoMana(int custoMana) {
		this.custoMana = custoMana;
	}
	
}
