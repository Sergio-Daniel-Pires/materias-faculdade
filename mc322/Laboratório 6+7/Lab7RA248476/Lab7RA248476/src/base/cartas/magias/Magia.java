package base.cartas.magias;
import base.cartas.Carta;
import java.util.UUID;

public class Magia extends Carta{
	
	public Magia(String nome, int custoMana) {
		super(nome, custoMana);
	}
	
	public Magia(UUID id, String nome, int custoMana) {
		super(id, nome, custoMana);
	}
	
}
