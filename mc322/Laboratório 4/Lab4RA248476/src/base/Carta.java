package base;
import java.util.UUID;

public class Carta {
	private UUID id;
	private String nome;
	private int custoMana;
	
	public Carta(String nome, int custoMana) {
		this.id = UUID.randomUUID();
		this.nome = nome;
		this.custoMana = custoMana;
	}
	
	// Metodo id
	public UUID getID() {
		return id;
	}
	
	// Metodos Nome
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	// Metodos CustoMana
	public int getCustoMana() {
		return custoMana;
	}
	public void setCustoMana(int custoMana) {
		this.custoMana = custoMana;
	}
	
	@Override
	public String toString() {
		String out = getNome() + " (ID: "+getID()+")\n";
		out +=  "Custo de Mana = "+getCustoMana()+"\n";
		return out;
	}
	
	public void usar(Carta alvo) {
		
	}
}
