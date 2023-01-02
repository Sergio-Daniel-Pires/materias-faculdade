
public class Main {

	public static void main(String[] args) {
		CartaLacaio lac1 = new CartaLacaio(1, "Frodo Bolseiro", 2, 1, 1);
		CartaLacaio lac2 = new CartaLacaio(2, "Aragon", 5, 7, 6);
		CartaLacaio lac3 = new CartaLacaio(3, "Legolas", 8, 4, 7);
		CartaLacaio lac6 = new CartaLacaio(7, "Murloc", 1, 1, 1);
		CartaLacaio lac7 = new CartaLacaio(8, "Alcolito da dor", 1, 1, 1);
		CartaLacaio lac8 = new CartaLacaio(9, "O Litch rei", 10, 10, 10);
		CartaMagia mag1 = new CartaMagia(4, "You shall not pass", 4, true, 7);
		CartaMagia mag2 = new CartaMagia(5, "Telecinese", 3, false, 2);

		// Questao 1
		CartaLacaio lac4 = new CartaLacaio(6, "Jaina Proudmore", 3);
		System.out.println("Quarto lacaio:\n"+lac4);
		
		// Questao 2
		lac1.setAtaque(5);
		lac1.setAtaque(lac3.getAtaque());
		System.out.println(lac1);
		
		//Questao 3
		System.out.println(lac3);

		// Questao 4
		CartaLacaio lac5 = new CartaLacaio(lac2);
		System.out.println(lac2);
		System.out.println(lac5);

		// Questao 5
		//System.out.println(mag1.nome);
		System.out.println(mag1.getNome());
	
		// Questao 6
		System.out.println(lac6.getNome());
		System.out.println(lac6.getAtaque());
		System.out.println(lac6.getVidaMaxima());
		lac6.buffar(2);
		System.out.println(lac6.getNome());
		System.out.println(lac6.getAtaque());
		System.out.println(lac6.getVidaMaxima());
		
		System.out.println(lac7.getNome());
		System.out.println(lac7.getAtaque());
		System.out.println(lac7.getVidaMaxima());
		lac7.buffar(4, 5);
		System.out.println(lac7.getNome());
		System.out.println(lac7.getAtaque());
		System.out.println(lac7.getVidaMaxima());

		System.out.println(lac8.getNome());
		System.out.println(lac8.getAtaque());
		System.out.println(lac8.getVidaMaxima());
		lac8.buffar(-9, -9);
		System.out.println(lac8.getNome());
		System.out.println(lac8.getAtaque());
		System.out.println(lac8.getVidaMaxima());

	}
}
