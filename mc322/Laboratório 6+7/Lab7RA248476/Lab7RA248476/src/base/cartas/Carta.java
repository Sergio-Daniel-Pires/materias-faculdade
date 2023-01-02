package base.cartas;
import java.util.UUID;

public class Carta implements Comparable<Carta> {
	private UUID id;
	private String nome;
	private int custoMana;
	
	public Carta(String nome, int custoMana) {
		this.id = UUID.randomUUID();
		this.nome = nome;
		this.custoMana = custoMana;
	}
	
	public Carta(UUID id, String nome, int custoMana) {
		this.id = id;
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
		String out = getNome();// + " (ID: "+getID()+")\n";
		out +=  " Custo de Mana = "+getCustoMana()+" ";
		return out;
	}
	
	public void usar(Carta alvo) {
		
	}
	
	@Override
	public boolean equals(Object obj) {
		if (this == obj) return true;
		if (!(obj instanceof Carta)) return false;
		Carta outra = (Carta) obj;
		// Verifica nomes e custo de mana
		if (outra.getNome() != nome) return false;
		if (outra.getCustoMana() != custoMana) return false;
		return true;
	}
	
	@Override
	public int compareTo(Carta o) {
		if (this.equals(o)) return 0;
		if  (this.getNome().equals(o.getNome())) {
			if (this.getCustoMana() < o.getCustoMana()) return -1;
			else if (this.getCustoMana() > o.getCustoMana()) return 1;
		}
		return this.getNome().compareTo(o.getNome());
	}

	
}
