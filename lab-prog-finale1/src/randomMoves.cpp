#include "randomMoves.h"

std::string randomMove(scacchiera& board, std::string position, char piece) {

	std::vector <int> move = traduttore::traduci(position + " " + position);
	std::vector <int> random;
	int colonna = 0;
	int riga = 0;
	std::string pos = "";

	switch (piece)
	{
	//---CAVALLO----
	case('c') : {
		int count = 8;
		while (count > 0) {
			//#1
			if (count == 8) {
				colonna = move.at(0) - 2;
				riga = move.at(1) - 1;
				if (rangeCheck(colonna, riga))
					if (friendlyCheckL(board, colonna, riga))
						return traduzionePerRandom(colonna, riga);
			}
			//#2
			if (count == 7) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 2;
				if (rangeCheck(colonna, riga))
					if (friendlyCheckL(board, colonna, riga))
						return traduzionePerRandom(colonna, riga);
			}
			//#3
			if (count == 6) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 2;
				if (rangeCheck(colonna, riga))
					if (friendlyCheckL(board, colonna, riga))
						return traduzionePerRandom(colonna, riga);
			}
			//#4
			if (count == 5) {
				colonna = move.at(0) + 2;
				riga = move.at(1) - 1;
				if (rangeCheck(colonna, riga))
					if (friendlyCheckL(board, colonna, riga))
						return traduzionePerRandom(colonna, riga);
			}
			//#5
			if (count == 4) {
				colonna = move.at(0) + 2;
				riga = move.at(1) + 1;
				if (rangeCheck(colonna, riga))
					if (friendlyCheckL(board, colonna, riga))
						return traduzionePerRandom(colonna, riga);
			}
			//#6
			if (count == 3) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 2;
				if (rangeCheck(colonna, riga))
					if (friendlyCheckL(board, colonna, riga))
						return traduzionePerRandom(colonna, riga);
			}
			//#7
			if (count == 2) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 2;
				if (rangeCheck(colonna, riga))
					if (friendlyCheckL(board, colonna, riga))
						return traduzionePerRandom(colonna, riga);
			}
			//#8
			else if (count == 1) {
				colonna = move.at(0) - 2;
				riga = move.at(1) + 1;
				if (rangeCheck(colonna, riga))
					if (friendlyCheckL(board, colonna, riga))
						return traduzionePerRandom(colonna, riga);
			}

			//end ciclo
			count--;
		}
		break;
	}
	case('C') : {
		int count = 8;
		while (count > 0) {
			//#1
			if (count == 3) {
				colonna = move.at(0) - 2;
				riga = move.at(1) - 1;
			}
			//#2
			if (count == 1) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 2;
			}
			//#3
			if (count == 2) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 2;
			}
			//#4
			if (count ==4 ) {
				colonna = move.at(0) + 2;
				riga = move.at(1) - 1;
			}
			//#5
			if (count == 6) {
				colonna = move.at(0) + 2;
				riga = move.at(1) + 1;
			}
			//#6
			if (count == 8) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 2;
			}
			//#7
			if (count == 7) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 2;
			}
			//#8
			else if (count == 5) {
				colonna = move.at(0) - 2;
				riga = move.at(1) + 1;
			}
			//controllo movimento
			if (rangeCheck(colonna, riga))
				if (friendlyCheckU(board, colonna, riga))
					return traduzionePerRandom(colonna, riga);
			//end ciclo
			count--;
		}
		break;
	}
	//----PEDONE----
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
			//#1
			if (count == 7) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 1;	
			}
			//#2
			if (count == 8) {
				colonna = move.at(0);
				riga = move.at(1) - 1;
			}
			//#3
			if (count == 6) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 1;
			}
			//#4
			if (count == 5) {
				colonna = move.at(0) + 1;
				riga = move.at(1);
			}
			//#5
			if (count == 1) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 1;
			}
			//#6
			if (count == 3) {
				colonna = move.at(0);
				riga = move.at(1) + 1;
			}
			//#7
			if (count == 2) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 1;
			}
			//#8
			if (count == 4) {
				colonna = move.at(0) - 1;
				riga = move.at(1) ;
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
			//#1
			if (count == 2) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 1;
			}
			//#2
			if (count == 1) {
				colonna = move.at(0);
				riga = move.at(1) - 1;
			}
			//#3
			if (count == 3) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 1;
			}
			//#4
			if (count == 4) {
				colonna = move.at(0) + 1;
				riga = move.at(1);
			}
			//#5
			if (count == 6) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 1;
			}
			//#6
			if (count == 8) {
				colonna = move.at(0);
				riga = move.at(1) + 1;
			}
			//#7
			if (count == 7) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 1;
			}
			//#8
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
			//#1
			if (count == 4) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 1;
			}
			//#2
			if (count == 2) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 1;
			}
			//#3
			if (count == 3) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 1;
			}
			//#4
			else if (count == 1) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 1;
			}
			//controllo move
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
			//#1
			if (count == 1) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 1;
			}
			//#2
			if (count == 3) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 1;
			}
			//#3
			if (count == 2) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 1;
			}
			//#4
			else if (count == 4) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 1;
			}
			//controllo move
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
			//#1
			if (count == 4) {
				colonna = move.at(0) ;
				riga = move.at(1) - 1;
			}
			//#2
			if (count == 3) {
				colonna = move.at(0) + 1;
				riga = move.at(1);
			}
			//#3
			if (count == 2) {
				colonna = move.at(0) - 1;
				riga = move.at(1);
			}
			//#4
			else if (count == 1) {
				colonna = move.at(0);
				riga = move.at(1) + 1;
			}
			//controllo move
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
			//#1
			if (count == 1) {
				colonna = move.at(0);
				riga = move.at(1) - 1;
			}
			//#2
			if (count == 2) {
				colonna = move.at(0) + 1;
				riga = move.at(1);
			}
			//#3
			if (count == 3) {
				colonna = move.at(0) - 1;
				riga = move.at(1);
			}
			//#4
			else if (count == 4) {
				colonna = move.at(0);
				riga = move.at(1) + 1;
			}
			//controllo move
			if (rangeCheck(colonna, riga)) {
				if (friendlyCheckU(board, colonna, riga))
					return traduzionePerRandom(colonna, riga);
			}
			count--;
		}
		break;
	}
	}
	return position;
}

//----------------------------------------------------------------
//----RANGE_CHECK-----
//Per non uscire dalle coordinate consentite
bool rangeCheck(int colonna, int riga) {
	if (colonna < 0 || colonna>7)
		return false;
	if (riga < 0 || riga>7)
		return false;
	return true;
}
//-----FRIENDLY_MOVES_UPPERCASE-----
//Contolla se la casella di arrivo e' gia' occupata da una 
//pedina dello stesso colore
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
//Contolla se la casella di arrivo e' gia' occupata da una 
//pedina dello stesso colore
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
