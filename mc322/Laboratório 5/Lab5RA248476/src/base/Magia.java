package base;

public class Magia extends Carta{
	private String descricao;
	
	public Magia(String nome, int custoMana, String descricao) {
		super(nome, custoMana);
		this.descricao = descricao;
	}
	
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	
	public String getDescricao() {
		return descricao;
	}
	
	public String toString() {
		String out = super.toString();
		out += "Descricao = " + descricao + "\n";
		return out;
	}
	
}
