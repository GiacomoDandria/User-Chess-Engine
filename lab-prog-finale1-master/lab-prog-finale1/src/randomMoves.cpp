//AUTORE: MARCO SQUARCINA

#include "randomMoves.h"

/*Questa funzione permette date le coordinate di partenza e il tipo di carattere, di restituire delle coordinate di 
  arrivo valide. E' semi random poiche' la scelta della pedina e' completamente random, mentre la scelta della posizione
  viene eseguita per tentativi mediante dei cicli while. Questo permette di velocizzare molto le giocate del computer.
  Vengono eseguiti diversi tipi di controlli: Range, Non venga mangiata una pedina dello stesso colore, non si vada "fuori"
  dalla scacchiera.  */
std::string randomMove(scacchiera& board, std::string position, char piece) {

	std::vector <int> move = traduttore::traduci(position + " " + position);  //vector contenente coordinate di partenza (in stile matrice)
	std::vector <int> random;						  //vector contenente coordinate di arrivo (in stile matrice)
	int colonna = 0;
	int riga = 0;
	std::string pos = "";							  //stringa per le coordinate di arrivo (pos = posizione)
	
	//Ogni pedina ha il suo case (controllo mosse valide)
	//Viene descritto solo il primo blocco di codice poiche' e' ripetitivo
	switch (piece)
	{
	//---CAVALLO----
	case('c') : {
		int count = 8;		//numero max mosse della pedina data
		while (count > 0) {	//ciclo per trovare mossa valida
			//Controllo #1
			if (count == 8) {		
				colonna = move.at(0) - 2;					//Inserisco le coordinate del caso in questione
				riga = move.at(1) - 1;	
			}
			//Controllo #2
			if (count == 7) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 2;
			}
			//Controllo #3
			if (count == 6) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 2;
			}
			//Controllo#4
			if (count == 5) {
				colonna = move.at(0) + 2;
				riga = move.at(1) - 1;
			}
			//Controllo #5
			if (count == 4) {
				colonna = move.at(0) + 2;
				riga = move.at(1) + 1;
			}
			//Controllo #6
			if (count == 3) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 2;
			}
			//Controllo #7
			if (count == 2) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 2;
			}
			//Controllo #8
			else if (count == 1) {
				colonna = move.at(0) - 2;
				riga = move.at(1) + 1;
			}
			//Controllo validita' coordinate
			if (rangeCheck(colonna, riga))					//Controllo se il range e' rispettato
				if (friendlyCheckL(board, colonna, riga))		//Controllo se ci sono pedine dello stesso colore
					return traduzionePerRandom(colonna, riga);	//Ritorno la stringa contenente le coordinate valide
			//Fine ciclo
			count--;
		}
		//Se non sono state trovate delle coordinate valide restituisco quelle di partenza; verra' segnalato
		//errore quando si tentera' la mossa
		break;
	}
	case('C') : {
		int count = 8;
		while (count > 0) {
			//Controllo #1
			if (count == 3) {
				colonna = move.at(0) - 2;
				riga = move.at(1) - 1;
			}
			//Controllo #2
			if (count == 1) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 2;
			}
			//Controllo #3
			if (count == 2) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 2;
			}
			//Controllo #4
			if (count ==4 ) {
				colonna = move.at(0) + 2;
				riga = move.at(1) - 1;
			}
			//Controllo #5
			if (count == 6) {
				colonna = move.at(0) + 2;
				riga = move.at(1) + 1;
			}
			//Controllo #6
			if (count == 8) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 2;
			}
			//Controllo #7
			if (count == 7) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 2;
			}
			//Controllo #8
			else if (count == 5) {
				colonna = move.at(0) - 2;
				riga = move.at(1) + 1;
			}
			//Controllo se le coordinate di arrivo sono valide. In caso contrario ripeto il ciclo
			if (rangeCheck(colonna, riga))
				if (friendlyCheckU(board, colonna, riga))
					return traduzionePerRandom(colonna, riga);
			//Fine ciclo
			count--;
		}
		break;
	}
	//----PEDONE----
	//Il pedone ha un controllo in piu', poiche' non pue' procedere se nelle diagonali c'e' una pedina (func. someone)
	case('p') : {
		int count = 3;
		while (count > 0) {
			//#1
			if (count == 3) {
				colonna = move.at(0)-1;
				riga = move.at(1)-1;
				if(rangeCheck(colonna,riga))
					if (someone(board, colonna, riga)) 
						if (friendlyCheckL(board, colonna, riga))
							return traduzionePerRandom(colonna, riga);				
			}
			//#3
			if (count == 2) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 1;
				if (rangeCheck(colonna, riga))
					if (someone(board, colonna, riga)) 
						if (friendlyCheckL(board, colonna, riga))
							return traduzionePerRandom(colonna, riga);
			}
			//#3
			else if (count == 1) {
				colonna = move.at(0);
				riga = move.at(1) - 1;
				if (rangeCheck(colonna, riga))
					if(!(someone(board,colonna,riga)))
						if (friendlyCheckL(board, colonna, riga))
							return traduzionePerRandom(colonna, riga);
			}
			count--;
		}
		break;
	}
	case('P') : {
		int count = 3;
		while (count > 0) {
			//#1
			if (count == 2) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 1;
				if (rangeCheck(colonna, riga))
					if (someone(board, colonna, riga))
						if (friendlyCheckU(board, colonna, riga))
							return traduzionePerRandom(colonna, riga);
			}
			//#3
			if (count == 3) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 1;
				if (rangeCheck(colonna, riga))
					if (someone(board, colonna, riga))
						if (friendlyCheckU(board, colonna, riga))
							return traduzionePerRandom(colonna, riga);
			}
			//#3
			else if (count == 1) {
				colonna = move.at(0);
				riga = move.at(1) + 1;
				if (rangeCheck(colonna, riga))
					if (!(someone(board, colonna, riga)))
						if (friendlyCheckU(board, colonna, riga))
							return traduzionePerRandom(colonna, riga);
			}
			count--;
		}
		break;
	}
	//----REGINA_E_RE----
	case('d') : case('r'):{
		int count = 8;
		while (count > 0) {
			//Controllo #1
			if (count == 6) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 1;
			}
			//Controllo #2
			if (count == 8) {
				colonna = move.at(0);
				riga = move.at(1) - 1;
			}
			//Controllo #3
			if (count == 5) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 1;
			}
			//Controllo #4
			if (count == 7) {
				colonna = move.at(0) + 1;
				riga = move.at(1);
			}
			//Controllo #5
			if (count == 3) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 1;
			}
			//Controllo #6
			if (count == 1) {
				colonna = move.at(0);
				riga = move.at(1) + 1;
			}
			//Controllo #7
			if (count == 2) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 1;
			}
			//Controllo #8
			if (count == 4) {
				colonna = move.at(0) - 1;
				riga = move.at(1);
			}
			//check correct movement
			if (rangeCheck(colonna, riga)) {
				if (friendlyCheckL(board, colonna, riga))
						return traduzionePerRandom(colonna, riga);
			}
			//decrementa ciclo
			count--;
		}
		break;
	}
	case ('D'):case('R'): {
		int count = 8;
		while (count > 0) {
			//Controllo #1
			if (count == 3) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 1;
			}
			//Controllo #2
			if (count == 1) {
				colonna = move.at(0);
				riga = move.at(1) - 1;
			}
			//Controllo #3
			if (count == 4) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 1;
			}
			//Controllo #4
			if (count == 2) {
				colonna = move.at(0) + 1;
				riga = move.at(1);
			}
			//Controllo #5
			if (count == 6) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 1;
			}
			//Controllo #6
			if (count == 8) {
				colonna = move.at(0);
				riga = move.at(1) + 1;
			}
			//Controllo #7
			if (count == 7) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 1;
			}
			//Controllo #8
			if (count == 5) {
				colonna = move.at(0) - 1;
				riga = move.at(1);
			}
			//check correct movement
			if (rangeCheck(colonna, riga)) {
				if (friendlyCheckU(board, colonna, riga))
					return traduzionePerRandom(colonna, riga);
			}
			//decrementa ciclo
			count--;
		}
		break;
	}
	//---ALFIERE---
	case('a') : {
		int count = 4;
		while (count > 0) {
			//Controllo #1
			if (count == 4) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 1;
			}
			//Controllo #2
			if (count == 2) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 1;
			}
			//Controllo #3
			if (count == 3) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 1;
			}
			//Controllo #4
			else if (count == 1) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 1;
			}
			//controllo movement
			if (rangeCheck(colonna, riga)) {
				if (friendlyCheckL(board, colonna, riga))
						return traduzionePerRandom(colonna, riga);
			}
			count--;
		}
		break;
	}
	case('A'): {
		int count = 4;
		while (count > 0) {
			//Controllo #1
			if (count == 1) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 1;
			}
			//Controllo #2
			if (count == 3) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 1;
			}
			//Controllo #3
			if (count == 2) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 1;
			}
			//Controllo #4
			else if (count == 4) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 1;
			}
			//controllo movement
			if (rangeCheck(colonna, riga)) {
				if (friendlyCheckU(board, colonna, riga))
					return traduzionePerRandom(colonna, riga);
			}
			count--;
		}
		break;
	}
	//---TORRE----
	case('t'): {
		int count = 4;
		while (count > 0) {
			//Controllo #1
			if (count == 4) {
				colonna = move.at(0) ;
				riga = move.at(1) - 1;
			}
			//Controllo #2
			if (count == 3) {
				colonna = move.at(0) + 1;
				riga = move.at(1);
			}
			//Controllo #3
			if (count == 2) {
				colonna = move.at(0) - 1;
				riga = move.at(1);
			}
			//Controllo #4
			else if (count == 1) {
				colonna = move.at(0);
				riga = move.at(1) + 1;
			}
			//controllo movement
			if (rangeCheck(colonna, riga)) {
				if (friendlyCheckL(board, colonna, riga))
						return traduzionePerRandom(colonna, riga);
			}
			count--;
		}
		break;
	}
	case ('T'): {
		int count = 4;
		while (count > 0) {
			//Controllo #1
			if (count == 1) {
				colonna = move.at(0);
				riga = move.at(1) - 1;
			}
			//Controllo #2
			if (count == 2) {
				colonna = move.at(0) + 1;
				riga = move.at(1);
			}
			//Controllo #3
			if (count == 3) {
				colonna = move.at(0) - 1;
				riga = move.at(1);
			}
			//Controllo #4
			else if (count == 4) {
				colonna = move.at(0);
				riga = move.at(1) + 1;
			}
			//controllo movement
			if (rangeCheck(colonna, riga)) {
				if (friendlyCheckU(board, colonna, riga))
					return traduzionePerRandom(colonna, riga);
			}
			count--;
		}
		break;
	}
	}
	//Se non ho trovato coordinate valide ritorno la posizione di partenza
	return position;
}

//----------------------------------------------------------------
//----RANGE_CHECK-----
//Controllo per non uscire dalle coordinate consentite dalla scacchiera
bool rangeCheck(int colonna, int riga) {
	if (colonna < 0 || colonna>7)
		return false;
	if (riga < 0 || riga>7)
		return false;
	return true;
}
//-----FRIENDLY_MOVES_UPPERCASE-----
  /*Contolla se la casella di arrivo e' gia' occupata da una 
    pedina dello stesso colore. Se e' dello stesso colore ritorna 
    false  */

bool friendlyCheckU(scacchiera& board, int colonna, int riga) {
	char piece = board.getPiece(riga, colonna);

	switch (piece)
	{
	case('P') : case('C') : case('T') : case('R') : case('D') :case('A'):
		return false;
	}
	return true;
}
//-----FRIENDLY_MOVES_LOWERCASE-----
/*Contolla se la casella di arrivo e' gia' occupata da una 
  pedina dello stesso colore. Se e' dello stesso colore ritorna 
  false  */
bool friendlyCheckL(scacchiera& board, int colonna, int riga) {
	char piece = board.getPiece(riga, colonna);

	switch (piece)
	{
	case('p'): case('c'): case('t'): case('r'): case('d'):case('a'):
		return false;
	}
	return true;
}
//----TRADUZIONE_PER_RANDOM----
//Traduce interi corrispondenti a riga e colonna della matrice in una stringa a livello giocatore
std::string traduzionePerRandom(int colonna, int riga) {
	std::string pos = "";
	pos = traduttore::traduciReverse(colonna, riga, colonna, riga);
	pos = pos.substr(0, 2);
	return pos;
}
//----SOMEONE_IN_DIAGONAL
/* Controlli utile per le mosse dei pedoni, permettono di ricevere TRUE
   se possono mangiare qualche pedina  */
bool someone(scacchiera&board, int colonna, int riga) {
	char who = board.getPiece(riga, colonna);
	if (who != ' ')
		return true;
	return false;
}
