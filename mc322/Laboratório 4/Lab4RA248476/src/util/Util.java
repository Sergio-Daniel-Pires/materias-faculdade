package util;
import base.*;

public class Util {
	public static void buffar(Lacaio lac, int a) {
		if (a > 0) {
			lac.setVidaMaxima(lac.getVidaMaxima() + a);
			lac.setVidaAtual(lac.getVidaAtual() + a);
			lac.setAtaque(lac.getAtaque() + a);
			alteraNomeFortalecido(lac);
		}
	}
	public static void buffar(Lacaio lac, int a, int v) {
		if (a > 0 && v > 0) {
			lac.setVidaMaxima(lac.getVidaMaxima() + v);
			lac.setVidaAtual(lac.getVidaAtual() + v);
			lac.setAtaque(lac.getAtaque() + a);
			alteraNomeFortalecido(lac);
		}
	}
	private static void alteraNomeFortalecido(Lacaio lac) {
		lac.setNome(lac.getNome() + " Buffed");
	}
	
	public static final int MAX_CARDS = 30;
}
