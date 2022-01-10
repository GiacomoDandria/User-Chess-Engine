#include "randomMerda.h"

std::string randomPosition(std::string position, char piece) {

	std::vector <int> move = traduttore::traduci(position + " " + position);
	std::vector <int> random;
	int colonna = 0;
	int riga = 0;
	std::string pos = "";

	//CANCELLO X DEBUG
	/*std::cout << "\n POSIZIONE: " << position << " " << position;
	std::cout << "\n POSIZIONE: " << move.at(0) << move.at(1) << move.at(2) << move.at(3) << "\n";*/

	
	switch (piece)
	{
	//---CAVALLO---
	case('c'):case('C'): {
		int count = 8;
		while (count > 0) {
			//#1
			if (count == 8) {
				colonna = move.at(0) - 2;
				riga = move.at(1) - 1;
				if (rangeCheck(colonna, riga)) 
					return traduzionePerRandom(colonna, riga);
			}
			//#2
			if (count == 7) {
				colonna = move.at(0) - 1;
				riga = move.at(1) - 2;
				if (rangeCheck(colonna, riga))
					return traduzionePerRandom(colonna, riga);
			}
			//#3
			if (count == 6) {
				colonna = move.at(0) + 1;
				riga = move.at(1) - 2;
				if (rangeCheck(colonna, riga))
					return traduzionePerRandom(colonna, riga);
			}
			//#4
			if (count == 5) {
				colonna = move.at(0) + 2;
				riga = move.at(1) - 1;
				if (rangeCheck(colonna, riga))
					return traduzionePerRandom(colonna, riga);
			}
			//#5
			if (count == 4) {
				colonna = move.at(0) + 2;
				riga = move.at(1) + 1;
				if (rangeCheck(colonna, riga))
					return traduzionePerRandom(colonna, riga);
			}
			//#6
			if (count == 3) {
				colonna = move.at(0) + 1;
				riga = move.at(1) + 2;
				if (rangeCheck(colonna, riga))
					return traduzionePerRandom(colonna, riga);
			}
			//#7
			if (count == 2) {
				colonna = move.at(0) - 1;
				riga = move.at(1) + 2;
				if (rangeCheck(colonna, riga))
					return traduzionePerRandom(colonna, riga);
			}
			//#8
			else if(count == 1) {
				colonna = move.at(0) - 2;
				riga = move.at(1) + 1;
				if (rangeCheck(colonna, riga))
					return traduzionePerRandom(colonna, riga);
			}

			//end ciclo
			count--;
		}
		

	}

	}

	return position;
}


//----RANGE_CHECK-----
//Per non uscire dalle coordinate consentite
bool rangeCheck(int colonna, int riga) {
	if (colonna < 0 || colonna>7)
		return false;
	if (riga < 0 || riga>7)
		return false;
	return true;
}
//----TRADUZIONE_PER_RANDOM----
std::string traduzionePerRandom(int colonna, int riga) {
	std::string pos = "";
	pos = traduttore::traduciReverse(colonna, riga, colonna, riga);
	pos = pos.substr(0, 2);
	return pos;
}