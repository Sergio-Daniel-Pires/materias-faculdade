import java.util.ArrayList;

/**
* Esta classe representa um Jogador aleatório (realiza jogadas de maneira aleatória) para o jogo LaMa (Lacaios & Magias).
* @see java.lang.Object
* @author Rafael Arakaki - MC302
*/

/** Método utilizado para tentar vencer jogos de LaMa
 * 
 * Não Utilizei os nomes exatos 'Agressivo', 'Controle' e 'curva de mana',
 * mas sinalizei qual tipo é qual
 * 
 * Utilizei uma arvore de prioridade para os tipos de comportamentos
 * A prioridade ficou dessa forma:
 * 1. Ganhar (Agressivo)
 *    O objetivo principal do jogo é derrotar o inimigo, então eu tenho
 *    uma funcao para verificar qual o maximo de dano que posso dar 
 *    no heroi adversario, caso for vencedor, eu o faço
 * 
 * 2. Evitar perder (Controle)
 *	  Caso nao de para vencer, temos que verificar se nao iremos perder
 *    ou seja, verificar se os lacaios do adversario tem dano suficiente
 *    para derrotar nosso heroi, neste caso temos que fazer trocas
 * 		
 * 		(Controle)
 * 		2.1 Se nao for possivel fazer trocas, verificar se ha um provocar
 * 			para colocar em campo e tentar mitigar o dano
 * 			obs: ja que provocar esta desabilitado, tentar usar magia em area
 * 		
 * 		(Controle)
 * 		2.0 Se nao tiver magia e/ou mana pra magia, tentar trocar os lacaios
 * 
 * 3. Escolher lacaios (Curva de Mana)
 * 	  Caso nao tiver como vencer nem risco de perder a gente pode
 *    so colocar lacaios em campos e/ou utilizar poder heroico
 * 		
 * 		3.1 Caso tenha lacaio para colocar em campo, colocar calculando
 * 			utilizando loop com recursao para somar maior dano (feito)
 * 
 * 		3.2 Caso não tenha lacaio, verificar se pode usar poder heroico (feito)
 * 		
 * 		3.3 Caso nao tenha nem lacaio, nem poder heroico, verificar se tem
 * 			moeda e se com ela da para usar poder heroico
 * 
 * (Controle)
 * 4. Escolher quem vamos atacar, aqui temos uma array list de lacaios, cada
 * 	  vez que um ataca, qlqr que seja o alvo, ele eh removido da lista, para
 * 	  evitar ataques duplos
 *    
 *    	4.1 A troca mais favoravel do mundo seria tirar todos os lacaios de la
 *    		sem perder lacaio ou menos da metade nossos, caso seja possivel
 *    
 *    	4.2 Tentar uma troca de um lacaio 'forte' (dobro de vida de um lacaio),
 *    		por um lacaio com menos
 * 	  
 * 		4.3 Caso formos levar mais de 50% de vida do heroi, tentar fazer uma
 * 			troca pelo menos, optando usar o(s) lacaio(s), com menos vida
 * 			para remover os lacaios com muita vida de la
 * 
 * 		4.4 Caso formos levar menos de 50% de dano, focar tudo no heroi inimigo
 */

public class JogadorRA248476 extends Jogador {
	private ArrayList<CartaLacaio> lacaios;
	private ArrayList<CartaLacaio> lacaiosOponente;
	
	/**
	  * O método construtor do JogadorAleatorio.
	  * 
	  * @param maoInicial Contém a mão inicial do jogador. Deve conter o número de cartas correto dependendo se esta classe Jogador que está sendo construída é o primeiro ou o segundo jogador da partida. 
	  * @param primeiro   Informa se esta classe Jogador que está sendo construída é o primeiro jogador a iniciar nesta jogada (true) ou se é o segundo jogador (false).
	  */
	public JogadorRA248476(ArrayList<Carta> maoInicial, boolean primeiro){
		primeiroJogador = primeiro;
		
		mao = maoInicial;
		lacaios = new ArrayList<CartaLacaio>();
		lacaiosOponente = new ArrayList<CartaLacaio>();
		
		// Mensagens de depuração:
		//System.out.println("*Classe JogadorRA248476* Sou o " + (primeiro?"primeiro":"segundo") + " jogador (classe: JogadorAleatorio)");
		//System.out.println("Mao inicial:");
		//for(int i = 0; i < mao.size(); i++)
		//	System.out.println("ID " + mao.get(i).getID() + ": " + mao.get(i));
	}

	
	private ArrayList<Jogada> MaximizarDanoMagias(ArrayList<Carta> minhasCartas, ArrayList<Jogada> letal, int manaAtual) {
		// Funcao recursiva para verificar o melhor combo de magias para se utilizar
		// Caso consiga colocar magia ele chama a funcao de novo para tentar colocar outra
		// caso acabe a mana, só retorna as ja colocadas
		Carta magiaMaisForte = null;
		for(int numCarta = 0; numCarta < minhasCartas.size(); numCarta++) {
			Carta cardAtual = minhasCartas.get(numCarta);
			if(cardAtual instanceof CartaMagia && cardAtual.getMana() <= manaAtual && (((CartaMagia) cardAtual).getMagiaTipo().name() == "ALVO" || ((CartaMagia) cardAtual).getMagiaTipo().name() == "AREA") &&(magiaMaisForte == null || ((CartaMagia) cardAtual).getMagiaDano() > ((CartaMagia) magiaMaisForte).getMagiaDano())){
				magiaMaisForte = cardAtual;
			}
		}
		if (magiaMaisForte == null) {
			return letal;
		}
		else {
			Jogada magia = new Jogada(TipoJogada.MAGIA, magiaMaisForte, null);
			letal.add(magia);
			int novaMana = manaAtual - magiaMaisForte.getMana();
			minhasCartas.remove(magiaMaisForte);
			return MaximizarDanoMagias(minhasCartas, letal, novaMana);
		}
	}
	
	private ArrayList<Jogada> UsarRestanteNoHeroi(ArrayList<CartaLacaio> lacaios){
		ArrayList<Jogada> jogadasNoHeroi = new ArrayList<Jogada>();
		for(int numLac = 0; numLac < lacaios.size(); numLac++) {
			Carta card = lacaios.get(numLac);
			Jogada lac = new Jogada(TipoJogada.ATAQUE, card, null);
			jogadasNoHeroi.add(lac);
		}
		return jogadasNoHeroi;
	}
	
	private ArrayList<Jogada> PossiveisTrocas(ArrayList<CartaLacaio> lacaios, ArrayList<CartaLacaio> lacaiosInimigos) {
		// Verifica se eh possivel realizar trocas favoraveis, alem disso
		// verifica qual e a melhor troca favoravel a se fazer (maximizar
		// dano a ser removivel ou lacaio de maior vida
		// ex, um lacaio nao vai atacar o lacaio de menos vida ou menos ataque
		ArrayList<Jogada> minhasJogadas = new ArrayList<Jogada>();
		for(int numAliado = 0; numAliado < lacaios.size(); numAliado++){
			// Para cada lacaio aliado, define o melhor lacaio inimigo nulo
			Carta aliado = lacaios.get(numAliado);
			Carta melhorInimigo = null;
			int melhorInimigoAtaque = 0;
			int melhorInimigoVida = 0;
			for(int numInimigo = 0; numInimigo < lacaiosInimigos.size(); numInimigo++){
				// Para cada lacaio inimigo, define se ele eh uma troca favoravel
				// Se for, verifica se eh melhor que a ultima definida, ou a ultima
				// precisa ser nula
				Carta inimigo = lacaiosInimigos.get(numInimigo);
				int aliadoAtaque = ((CartaLacaio) aliado).getAtaque();
				int aliadoVida = ((CartaLacaio) aliado).getVidaAtual();
				int inimigoAtaque = ((CartaLacaio) inimigo).getAtaque();
				int inimigoVida = ((CartaLacaio) inimigo).getVidaAtual();
				if(aliadoAtaque >= inimigoVida && inimigoAtaque < aliadoVida) {
					if(melhorInimigo == null) {						
						melhorInimigo = inimigo;
					}else {
						melhorInimigoAtaque = ((CartaLacaio) melhorInimigo).getAtaque();
						melhorInimigoVida = ((CartaLacaio) melhorInimigo).getVidaAtual();
						if(melhorInimigoVida < inimigoAtaque || melhorInimigoAtaque < inimigoVida) {
							melhorInimigo = inimigo;
						}
					}
				}
			}
			if(melhorInimigo != null) {
				Jogada lac = new Jogada(TipoJogada.ATAQUE, aliado, melhorInimigo);
				minhasJogadas.add(lac);
				lacaiosInimigos.remove(melhorInimigo);
			}
			melhorInimigo = null;
		}
		return minhasJogadas;
	}
		
	private int ContarDanoJogada(ArrayList<Jogada> atual) {
		// conta o dano total de uma jogada
		int danoTotal = 0;
		for(int numCarta = 0; numCarta < atual.size(); numCarta++) {
			Jogada jogadaAtual = atual.get(numCarta);
			Carta cardAtual = jogadaAtual.getCartaJogada();
			if(cardAtual instanceof CartaLacaio) {
				danoTotal += ((CartaLacaio) cardAtual).getAtaque();
			}
			else if(cardAtual instanceof CartaMagia) {
				danoTotal += ((CartaMagia) cardAtual).getMagiaDano();
			}
			else {
				// significa que é magia, que é 1 dano
				danoTotal += 1;
			}
		}
		return danoTotal;
	}
	
	private ArrayList<CartaLacaio> removeLacaiosUsados(ArrayList<CartaLacaio> podemAtacar, ArrayList<Jogada> jogadasFeita){
		ArrayList<CartaLacaio> naoUtilizados = new ArrayList<CartaLacaio>();
		naoUtilizados.addAll(podemAtacar);
		for(int numLac = 0; numLac < jogadasFeita.size(); numLac++) {
			Jogada jogada = jogadasFeita.get(numLac);
			Carta card = jogada.getCartaJogada();
			naoUtilizados.remove(card);
		}
		return naoUtilizados;
	}
	
	/*
	private ArrayList<Jogada> DescerCartas(ArrayList<Jogada> jogadaDescerCartas, ArrayList<Carta> lacaios, int manaAtual) {
		// Funcao recursiva para verificar o melhor combo de lacaios para se utilizar
		// Caso consiga colocar mais de um lacaio ele chama a funcao de novo para
		// caso acabe a mana, só retorna as ja colocadas tentar colocar outra
		Carta lacaioMaisForte = null;
		for(int numCarta = 0; numCarta < lacaios.size(); numCarta++) {
			Carta cardAtual = lacaios.get(numCarta);
			if(cardAtual instanceof CartaLacaio) {				
				if(cardAtual.getMana() <= manaAtual && (lacaioMaisForte == null || ((CartaLacaio) cardAtual).getAtaque() > ((CartaLacaio) lacaioMaisForte).getAtaque())){
					lacaioMaisForte = cardAtual;
				}
			}
		}
		if (lacaioMaisForte == null) {
			return jogadaDescerCartas;
		}
		else {
			Jogada lac = new Jogada(TipoJogada.LACAIO, lacaioMaisForte, null);
			jogadaDescerCartas.add(lac);
			int novaMana = manaAtual - lacaioMaisForte.getMana();
			lacaios.remove(lacaioMaisForte);
			return DescerCartas(jogadaDescerCartas, lacaios, novaMana);
		}
	}*/
	private ArrayList<Jogada> DescerCartas(ArrayList<Carta> mao, int manaAtual) {
		// Funcao recursiva para verificar o melhor combo de lacaios para se utilizar
		// Caso consiga colocar mais de um lacaio ele chama a funcao de novo para
		// caso acabe a mana, só retorna as ja colocadas tentar colocar outra
		ArrayList<Carta> lacaios = new ArrayList<Carta>();
		for(int i = 0; i < mao.size(); i++) {
			if(mao.get(i) instanceof CartaLacaio) {
				lacaios.add(mao.get(i));
			}
		}	
		ArrayList<ArrayList<Carta>> todasJogadas = new ArrayList<ArrayList<Carta>>();
		permutation(todasJogadas, new ArrayList<Carta>(), lacaios);
		ArrayList<Jogada> melhorJogada = new ArrayList<Jogada>();
		
		for(int numJogada = 0; numJogada < todasJogadas.size(); numJogada++) {
			ArrayList<Carta> jogadaAtual = todasJogadas.get(numJogada);
			// Aqui verifica os custos das jogadas e as cria
			ArrayList<Jogada> possivelJogada = new ArrayList<Jogada>();
			int manaDisponivel = manaAtual;
			
			for(int numLac = 0; numLac < jogadaAtual.size(); numLac++) {
				Carta lacaioAtual = jogadaAtual.get(numLac);
				if(manaDisponivel - lacaioAtual.getMana() >= 0) {
					manaDisponivel -= lacaioAtual.getMana();
					possivelJogada.add(new Jogada(TipoJogada.LACAIO, lacaioAtual, null));
				}
			// Aqui eu priorizo colocar mais lacaios, que deem o mesmo tanto de dano
			// e com o menor custo possivel
			}
			if(ContarDanoJogada(possivelJogada) > ContarDanoJogada(melhorJogada)) {
				melhorJogada = possivelJogada;
			}
		}
		return melhorJogada;
	}

	private static void permutation(ArrayList<ArrayList<Carta>> accum, ArrayList<Carta> prefix, ArrayList<Carta> nums) {
	    int tamanho = nums.size();
	    if (tamanho == 0) {
	        accum.add(prefix);
	    } else {
	        for (int i = 0; i < tamanho; ++i) {
	            ArrayList<Carta> newPrefix = new ArrayList<Carta>();
	            ArrayList<Carta> numsLeft = new ArrayList<Carta>();
	            newPrefix.addAll(prefix);
	            newPrefix.add(nums.get(i));
	            numsLeft.addAll(nums);
	            numsLeft.remove(i);
	            permutation(accum, newPrefix, numsLeft);
	        }
	    }
	}

	
	private ArrayList<Jogada> BuffsNaMao(ArrayList<Carta> mao) {
		ArrayList<Jogada> jogarBuff = new ArrayList<Jogada>();
		for(int numCarta = 0; numCarta < mao.size(); numCarta++) {
			Carta card = mao.get(numCarta);
			if(card instanceof CartaMagia && ((CartaMagia) card).getMagiaTipo() == TipoMagia.BUFF) {
				jogarBuff.add(new Jogada(TipoJogada.MAGIA, card, null));
			}
		}
		return jogarBuff;
	}
	
	private int compilaJogadas(ArrayList<Jogada> minhasJogadas, ArrayList<Jogada> jogadasParciais, ArrayList<Carta> mao, int manaInicial){
		// Funcao simples para juntar dois ArrayLists de jogadas e retorna a mana
		for(int numJogada = 0; numJogada < jogadasParciais.size(); numJogada++) {
			Jogada jogadaAtual = jogadasParciais.get(numJogada);
			minhasJogadas.add(jogadaAtual);
			if(jogadaAtual.getTipo() != TipoJogada.ATAQUE){
				Carta card = jogadaAtual.getCartaJogada();
				mao.remove(card);
				manaInicial -= card.getMana();
			}
		}
		return manaInicial;
	}
	
	private int compilaJogadas(ArrayList<Jogada> minhasJogadas, Jogada jogadaAtual, ArrayList<Carta> mao, int manaInicial){
		// Funcao simples para juntar dois ArrayLists de jogadas e retorna a mana
		minhasJogadas.add(jogadaAtual);
		if(jogadaAtual.getTipo() != TipoJogada.ATAQUE){
			Carta card = jogadaAtual.getCartaJogada();
			mao.remove(card);
			manaInicial -= card.getMana();
		}
		return manaInicial;
	}
	
	private ArrayList<Jogada> RemoveDanoLetal(ArrayList<CartaLacaio> meus, ArrayList<CartaLacaio> oponentes, ArrayList<Carta> mao, int minhaMana){
		ArrayList<Jogada> removerLetal = new ArrayList<Jogada>();
		for(int numCarta = 0; numCarta < mao.size(); numCarta++) {
			Carta card = mao.get(numCarta);
			if(card instanceof CartaMagia && minhaMana - card.getMana() >= 0 && ((CartaMagia) card).getMagiaTipo() == TipoMagia.AREA) {
				removerLetal.add(new Jogada(TipoJogada.MAGIA, card, null));
				minhaMana -= card.getMana();
				ArrayList<CartaLacaio> copiasLacaios = new ArrayList<CartaLacaio>();
				copiasLacaios.addAll(oponentes);
				for(int numOponente = 0; numOponente < copiasLacaios.size(); numOponente++) {
					CartaLacaio lacAtual = copiasLacaios.get(numOponente);
					if(lacAtual.getVidaAtual() - 4 < 1)
						oponentes.remove(lacAtual);
				}
				break;
			}
		}
		return removerLetal;
	}
	
	/**
	  * Um método que processa o turno de cada jogador. Este método deve retornar as jogadas do Jogador decididas para o turno atual (ArrayList de Jogada).
	  * 
	  * @param mesa   O "estado do jogo" imediatamente antes do início do turno corrente. Este objeto de mesa contém todas as informações 'públicas' do jogo (lacaios vivos e suas vidas, vida dos heróis, etc).
	  * @param cartaComprada   A carta que o Jogador recebeu neste turno (comprada do Baralho). Obs: pode ser null se o Baralho estiver vazio ou o Jogador possuir mais de 10 cartas na mão.
	  * @param jogadasOponente   Um ArrayList de Jogada que foram os movimentos utilizados pelo oponente no último turno, em ordem.
	  * @return            um ArrayList com as Jogadas decididas
	  */
	public ArrayList<Jogada> processarTurno (Mesa mesa, Carta cartaComprada, ArrayList<Jogada> jogadasOponente){
		int minhaMana, minhaVida, oponenteVida;
		ArrayList<CartaLacaio> copiaLacaios, copiaLacaiosOponentes = new ArrayList<CartaLacaio>();
		ArrayList<Jogada> minhasJogadas = new ArrayList<Jogada>();
		
		if(cartaComprada != null)
			mao.add(cartaComprada);
		if(primeiroJogador){
			minhaMana = mesa.getManaJog1();
			minhaVida = mesa.getVidaHeroi1();
			oponenteVida = mesa.getVidaHeroi2(); //Adicionado depois
			lacaios = mesa.getLacaiosJog1();
			lacaiosOponente = mesa.getLacaiosJog2();
			//System.out.println("--------------------------------- Começo de turno pro jogador1");
		}
		else{
			minhaMana = mesa.getManaJog2();
			minhaVida = mesa.getVidaHeroi2();
			oponenteVida = mesa.getVidaHeroi1(); //Adicionado depois
			lacaios = mesa.getLacaiosJog2();
			lacaiosOponente = mesa.getLacaiosJog1();
			//System.out.println("--------------------------------- Começo de turno pro jogador2");
		}
		
		// Aqui verifica se posso ganhar, contabilizando dano da mesa,
		// das magias na mao e do poder heroico somado, caso de, ganha
		ArrayList<Jogada> jogadaTodaNoHeroi = new ArrayList<Jogada>();
		jogadaTodaNoHeroi = UsarRestanteNoHeroi(lacaios);
		ArrayList<Carta> copiaMao = new ArrayList<Carta>();
		copiaMao.addAll(mao);
		jogadaTodaNoHeroi = MaximizarDanoMagias(copiaMao, jogadaTodaNoHeroi, minhaMana);
		int danoTotal = ContarDanoJogada(jogadaTodaNoHeroi);
		if(danoTotal >= oponenteVida) {
			return jogadaTodaNoHeroi;
		}
		
		// Aqui verifica se eu PODERIA perder no proximo turno, tenta
		// realizar trocas favoraveis
		int possivelDanoInimigo = 0;
		for(int numLac = 0; numLac < lacaiosOponente.size(); numLac++) {
			Carta card = lacaiosOponente.get(numLac);
			possivelDanoInimigo += ((CartaLacaio) card).getAtaque();
		}
		if(possivelDanoInimigo > minhaVida) {	
			ArrayList<Jogada> jogadaRemoverLetal = new ArrayList<Jogada>();
			jogadaRemoverLetal = RemoveDanoLetal(lacaios, lacaiosOponente, mao, minhaMana);
			minhaMana = compilaJogadas(minhasJogadas, jogadaRemoverLetal, mao, minhaMana);
		}
		
		// PASSADOS TOPICOS 1 e 2 FOCAMOS NA LISTA DO 3 EM DIANTE
		ArrayList<CartaLacaio> podemAtacar = new ArrayList<CartaLacaio>();
		podemAtacar.addAll(lacaios);
		
		// Verifica se é possivel realizar trocas favoraveis nos inimigos
		//Utiliza copias das listas de lacaios
		copiaLacaios = new ArrayList<CartaLacaio>();
		copiaLacaios.addAll(lacaios);
		copiaLacaiosOponentes = new ArrayList<CartaLacaio>();
		copiaLacaiosOponentes.addAll(lacaiosOponente);
		
		ArrayList<Jogada> jogadasTrocasFavoraveis = new ArrayList<Jogada>();
		jogadasTrocasFavoraveis = PossiveisTrocas(copiaLacaios, copiaLacaiosOponentes);
		
		// remove lacaios usados
		podemAtacar = removeLacaiosUsados(podemAtacar, jogadasTrocasFavoraveis);
		
		// Verifica se é possivel realizar uma troca 'semi favoravel'
		// Neste caso, trocar um lacaio com pouca vida e/ou ferido
		// por um lacaio de la com o dobro de ataque
		
		/**
		 * Metodo ainda nao adicionado, favor ter paciencia sergio do futuro
		 * ass: sergio do passado
		 */
		
		// Verifica se vamos tomar muito dano no heroi (mais de 50%)
		// caso sim, remove pelo menos um lacaio forte, nao eh o ideal
		// mas em casos extremos eh util
		
		/**
		 * Metodo ainda nao adicionado, favor ter paciencia sergio do futuro
		 * ass: sergio do passado
		 */
		
		// Verifica se ainda temos lacaios que nao atacaram, caso sim, utiliza
		copiaLacaios = new ArrayList<CartaLacaio>();
		copiaLacaios.addAll(podemAtacar);
		ArrayList<Jogada> jogadaAtacarFace = new ArrayList<Jogada>();
		if(podemAtacar.size() > 0) {
			jogadaAtacarFace = UsarRestanteNoHeroi(podemAtacar);
		}
		
		// Verifica qual a melhor formas de descer as cartas
		ArrayList<Jogada> jogadaDescerCartas = new ArrayList<Jogada>();
		copiaMao = new ArrayList<Carta>();
		copiaMao.addAll(mao);
		//jogadaDescerCartas = DescerCartas(jogadaDescerCartas, copiaMao, minhaMana);
		jogadaDescerCartas = DescerCartas(copiaMao, minhaMana);
		
		minhaMana = compilaJogadas(minhasJogadas, jogadasTrocasFavoraveis, mao, minhaMana);
		minhaMana = compilaJogadas(minhasJogadas, jogadaAtacarFace, mao, minhaMana);
		minhaMana = compilaJogadas(minhasJogadas, jogadaDescerCartas, mao, minhaMana);
		
		// Aqui todos os lacaios ja foram utilizados, entao se ainda houver mana:
		// 1. buffamos 1 lacaio se possivel, se tivermos buff E pelo menos um lacaio
		if(minhaMana >= 2) {
			ArrayList<Jogada> jogarBuff = BuffsNaMao(mao);
			if(jogarBuff.size() > 0 && podemAtacar.size() > 0) {
				for(int manaRestante = minhaMana; manaRestante >= 2; manaRestante -= 2) {
					if(jogarBuff.size() > 0 && podemAtacar.size() > 0) {
						Jogada atual = jogarBuff.get(0);
						jogarBuff.remove(atual);
						atual.setCartaAlvo(podemAtacar.get(0));
						minhaMana = compilaJogadas(minhasJogadas, atual, mao, minhaMana);
					}
				}
			}
		}
		// 2. podemos usar o poder heroico
		if(minhaMana >= 2) {
			minhasJogadas.add(new Jogada(TipoJogada.PODER, null, null));
		}
		
		return minhasJogadas;
	}
}