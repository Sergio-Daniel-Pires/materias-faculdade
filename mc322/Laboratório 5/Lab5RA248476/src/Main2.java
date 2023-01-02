import java.util.HashSet;
import java.util.Iterator;
import java.util.TreeSet;
import base.*;

public class Main2 {
	public static void main(String[] args) {
		
		// Preparacao
		HashSet<Carta> HashCarta = new HashSet<Carta>();
		TreeSet<Carta> TreeCarta = new TreeSet<Carta>();
		RandomStringGen gerador = new RandomStringGen(5);
		for (int i = 0; i < 10000; i++) {
			HashCarta.add(new Lacaio(gerador.nextString() , 1, 1, 1));
			TreeCarta.add(new Lacaio(gerador.nextString(), 1, 1, 1));
		}
		
		// Atividade 2
		long atv2 = System.nanoTime();
		for (Carta atual : HashCarta) {
            HashCarta.contains(atual);
        }
		System.out.println("A operacao demorou " + (System.nanoTime() - atv2) / 1000000 + " ms");
		
		// Atividade 3
		long atv3 = System.nanoTime();
		for (Carta atual : TreeCarta) {
			TreeCarta.contains(atual);
        }
		System.out.println("A operacao demorou " + (System.nanoTime() - atv3) / 1000000 + " ms");
	
		// Atividade 4
		// Nao aceita, cada item repetido tem o mesmo hash, logo ocupam a mesma posicao, logo, só existe um
	}
}
