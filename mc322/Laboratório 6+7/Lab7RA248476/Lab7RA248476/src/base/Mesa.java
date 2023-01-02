package base;
import java.util.ArrayList;

import base.cartas.*;
import util.Util;

public class Mesa {
	private ArrayList<Carta> maoP;
	private ArrayList<Carta> maoS;
	private ArrayList<Carta> lacaiosP;
	private ArrayList<Carta> lacaiosS;
	private int poderHeroiP;
	private int poderHeroiS;
	private int manaP;
	private int manaS;
	
	public Mesa(){
		this.maoP = new ArrayList<Carta>();
		this.maoS = new ArrayList<Carta>();
		this.lacaiosP = new ArrayList<Carta>();
		this.lacaiosS = new ArrayList<Carta>();
		this.poderHeroiP = Util.PODER_HEROI;
		this.poderHeroiS = Util.PODER_HEROI;
		this.manaP = 1;
		this.manaS = 1;
	}
	
	public Mesa(ArrayList<Carta> maoP, ArrayList<Carta> maoS, ArrayList<Carta> lacaiosP, ArrayList<Carta> lacaiosS, int poderHeroiP, int poderHeroiS, int manaP, int manaS){
		this.maoP = maoP;
		this.maoS = maoS;
		this.lacaiosP = lacaiosP;
		this.lacaiosS = lacaiosS;
		this.poderHeroiP = poderHeroiP;
		this.poderHeroiS = poderHeroiS;
		this.manaP = manaP;
		this.manaS = manaS;
	}
	
	// Gets e sets
	public ArrayList<Carta> getMaoP() {
		return maoP;
	}

	public void setMaoP(ArrayList<Carta> maoP) {
		this.maoP = maoP;
	}

	public ArrayList<Carta> getMaoS() {
		return maoS;
	}

	public void setMaoS(ArrayList<Carta> maoS) {
		this.maoS = maoS;
	}

	public ArrayList<Carta> getLacaiosP() {
		return lacaiosP;
	}

	public void setLacaiosP(ArrayList<Carta> lacaiosP) {
		this.lacaiosP = lacaiosP;
	}

	public ArrayList<Carta> getLacaiosS() {
		return lacaiosS;
	}

	public void setLacaiosS(ArrayList<Carta> lacaiosS) {
		this.lacaiosS = lacaiosS;
	}

	public int getPoderHeroiP() {
		return poderHeroiP;
	}

	public void setPoderHeroiP(int poderHeroiP) {
		this.poderHeroiP = poderHeroiP;
	}

	public int getPoderHeroiS() {
		return poderHeroiS;
	}

	public void setPoderHeroiS(int poderHeroiS) {
		this.poderHeroiS = poderHeroiS;
	}

	public int getManaP() {
		return manaP;
	}

	public void setManaP(int manaP) {
		this.manaP = manaP;
	}

	public int getManaS() {
		return manaS;
	}

	public void setManaS(int manaS) {
		this.manaS = manaS;
	}
	
	public void decPoderHeroi(int quantidade, char autor) {
		if(autor == 'P') {
			this.poderHeroiP = getPoderHeroiP() - quantidade; 
		}else {
			this.poderHeroiS = getPoderHeroiS() - quantidade; 
		}
	}
	
	public void decMana(int quantidade, char autor) {
		if(autor == 'P') {
			this.manaP = getManaP() - quantidade; 
		}else {
			this.manaS = getManaS() - quantidade;
		}
	}
	
	public Carta sacarCarta(char autor) {
		ArrayList<Carta> baralho = null;
		if(autor == 'P') {
			baralho = this.lacaiosP;
		}else {
			baralho = this.lacaiosS;
		}

		return baralho.remove(baralho.size() - 1);
	}
	
}
