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
		this.ataque = ataque;
		this.vidaAtual = vida;
		this.vidaMaxima = vida;
		this.custoMana = mana;
	}
	
	public CartaLacaio(int ID, String nome, int mana) {
		this.ID = ID;
		this.nome = nome;
		this.custoMana = mana;
	}
	
	public CartaLacaio (CartaLacaio origem) {
		this.ID = origem.getID();
		this.nome = origem.getNome();
		this.ataque = origem.getAtaque();
		this.vidaAtual = origem.getVidaAtual();
		this.vidaMaxima = origem.getVidaMaxima();
		this.custoMana = origem.getCustoMana();
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
	
	// Questao 6
	public void alteraNomeFortalecido(){
		this.nome = this.nome + " Buffed";
	}
	
	public void buffar(int a, int v) {
		if (a > 0 && v > 0) {			
		this.ataque = this.ataque + a;
		this.vidaMaxima = this.vidaMaxima + v;
		alteraNomeFortalecido();
		}
	}
	
	public void buffar(int a) {
		if (a > 0) {
			this.ataque = this.ataque + a;
			this.vidaMaxima = this.vidaMaxima + a;
			alteraNomeFortalecido();
		}
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
