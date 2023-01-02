

public class CartaMagia {
	private int ID;
	private String nome;
	private int dano;
	private boolean area;
	private int custoMana;
	
	public CartaMagia(int ID, String nome, int dano, boolean area, int mana) {
		this.ID = ID;
		this.nome = nome;
		this.dano = dano;
		this.area = area;
		this.custoMana = mana;
	}
	
	@Override
	public String toString() {
		String out = getNome() + " (ID: "+getID()+")\n";
		out +=  "Dano = "+getDano()+"\n";
		out +=  "Em area? = "+getArea()+"\n";
		out +=  "Custo = "+getCustoMana()+"\n";
		return out;
	}

	public int getID() {
		return ID;
	}

	public void setID(int iD) {
		ID = iD;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getDano() {
		return dano;
	}

	public void setDano(int dano) {
		this.dano = dano;
	}

	public boolean getArea() {
		return area;
	}

	public void setArea(boolean area) {
		this.area = area;
	}

	public int getCustoMana() {
		return custoMana;
	}

	public void setCustoMana(int custoMana) {
		this.custoMana = custoMana;
	}
	
	
}
