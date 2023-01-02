package base.cartas;
import java.util.Objects;
import base.cartas.Carta;

public class Lacaio extends Carta{
	private int ataque;
	private int vidaAtual;
	private int vidaMaxima;
	private HabilidadesLacaio habilidade;
	
	public Lacaio(String nome, int custoMana, int ataque, int vida) {
		super(nome, custoMana);
		this.ataque = ataque;
		this.vidaAtual = vida;
		this.vidaMaxima = vida;
	}
	
	public Lacaio(String nome, int custoMana, int ataque, int vida, HabilidadesLacaio habilidade) {
		super(nome, custoMana);
		this.ataque = ataque;
		this.vidaAtual = vida;
		this.vidaMaxima = vida;
		this.habilidade = habilidade;
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
	
	@Override
	public String toString() {
		String out = super.toString();
		out +=  "Ataque = "+getAtaque()+" ";
		out +=  "Vida atual = "+getVidaAtual()+" ";
		out +=  "Vida Maxima = "+getVidaMaxima()+" ";
		out +=  "Habilidade = "+getHabilidade()+"";
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
		Lacaio downcast = (Lacaio) alvo;
		downcast.setVidaAtual(downcast.getVidaAtual() - ataque);
	}
	
	@Override
	public int hashCode() {
		return Objects.hash(ataque, vidaAtual, vidaMaxima);
	}
	
	public HabilidadesLacaio getHabilidade() {
		return this.habilidade;
	}

	public void setHabilidade(HabilidadesLacaio habilidade) {
		this.habilidade = habilidade;
	}
	
}
