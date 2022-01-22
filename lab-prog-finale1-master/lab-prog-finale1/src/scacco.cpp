//Autore: Giacomo D'Andria

#include"scacco.h"

//'a' e 'b' servono ad indicare di quanto incrementare le coordinate del controllo
//a sta per la colonna e b per la riga
bool scacco::check(scacchiera &board, char inputRe, int inColonna, int inRiga) {
	char t = ' '; 
	char c = ' ';
	char a = ' ';
	char d = ' ';
	char r = ' ';
	char p = ' ';

	//a seconda del re passato come input, le pedine saranno bianche o nere
	if (inputRe == 'R') {
		t = 't';
		c = 'c';
		a = 'a';
		d = 'd';
		r = 'r';
		p = 'p';
	}
	else if (inputRe == 'r') {
		t = 'T';
		c = 'C';
		a = 'A';
		d = 'D';
		r = 'R';
		p = 'P';
	}
	
	//il vector re conterra' le coordinate del re passate come input alla funzione
	std::vector<int> re = board.findRe(inputRe);
	
	/*muovo ipotetica posizione re (nel caso in cui si stia facendo il check dello
	  scaccomatto, altrimenti inRiga e inColonna sono a zero, dunque la posizione del
	  re rimane la stessa)*/
	re.at(0) += inRiga;
	re.at(1) += inColonna;

	//Controllo verticale delle pedine presenti "sotto" il re
	for (auto i = re.at(0); i < 8; i++) {
		char temp = board.getPiece(i, re.at(1));
		
		if (i == re.at(0) + 1) {
			if (temp == r) { //se mi sposto di una casella ed e' presente un re
				return true; //sono sotto scacco
			}
		}
		if (temp == d || temp == t ) { //se sono presenti torri o regine avversarie
			return true; //il re e' sotto scacco
		}
		if (temp != 0x20) { //in tutti gli altri casi esco e passo al controllo
			if(temp != inputRe) {
				break;
			}
		}
	}

	//controllo verticale delle pedine presenti "sopra" il re
	for (auto i = re.at(0); i >= 0; i--) {
		char temp = board.getPiece(i, re.at(1));

		if (i == re.at(0) - 1) {
			if (temp == r) { //sotto scacco se c'e' un re
				return true;
			}
		}
		if (temp == d || temp == t) { //sotto scacco con torri o regine
			return true;
		}
		if (temp != 0x20) { //in tutti gli altri casi esco e passo al controllo
			if (temp != inputRe) {
				break;
			}
		}
	}

	//controllo orizzontale "sinistro" pedine presenti
	for (auto i = re.at(1); i >= 0; i--) {
		char temp = board.getPiece(re.at(0), i);
		
		//controllo se il re puo' essere mangiato
		if (i == re.at(1) - 1) {
			if (temp == r) {
				return true;
			}
		}
		if (temp == d || temp == t) {
			return true;
		}
		if (temp != 0x20) {
			if (temp != inputRe) {
				break;
			}
		}
	}


	//controllo orizzontale "destro" pedine presenti
	for (auto i = re.at(1); i < 8; i++) {
		char temp = board.getPiece(re.at(0), i);
		
		//controllo se il re puo' essere mangiato
		if (i == re.at(1) + 1) {
			if (temp == r) {
				return true;
			}
		}
		if (temp == d || temp == t) {
			return true;
		}
		if (temp != 0x20) {
			if (temp != inputRe) {
				break;
			}
		}
	}

	/*controllo obliquo presenza pedoni, divide il controllo nel caso di pedine maiuscole e minuscole perché i pedoni
	  possono soltanto "andare avanti" nella scacchiera*/
	
	//check per pedine maiuscole
	if (inputRe == 'R') {
		if ((board.getPiece(re.at(0) + 1, re.at(1) + 1) == p) || (board.getPiece(re.at(0) + 1, re.at(1) - 1) == p)) {
			return true;
		}
	}
	//check per pedine minuscole
	else if (inputRe == 'r') {
		if ((board.getPiece(re.at(0) - 1, re.at(1) - 1) == p) || (board.getPiece(re.at(0) - 1, re.at(1) + 1) == p)) {
			return true;
		}
	}


	//controllo diagonali "in alto a sinistra" presenza alfieri o regina o re (diminuiscono entrambi gli indici)
	int counter1 = re.at(1);
	for (auto i = re.at(0); i >= 0; i--) {
		//se esco dalla scacchiera, la posizione non e' valida
		if (counter1 < 0) {
			break;
		}
		
		char temp = board.getPiece(i, counter1);

		//controllo se il re puo' essere mangiato
		if ((i == re.at(0) -1) && (counter1 == re.at(1)-1)) {
			if (temp == r) {
				return true;
			}
		}
		if (temp == d || temp == a) {
			return true;
		}
		if (temp != 0x20) {
			if (temp != inputRe) {
				break;
			}
		}
		counter1--;
	}

	//controllo diagonali "in basso a destra" presenza alfieri o regina o re (aumentano entrambi gli indici)
	int counter2 = re.at(1);
	for (auto i = re.at(0); i < 8; i++) {
		if (counter2 >= 8) {
			break;
		}
		
		char temp = board.getPiece(i, counter2);

		//controllo se il re puo' essere mangiato
		if ((i == re.at(0) + 1) && (counter2 == re.at(1) + 1))
			if (temp == r) {
				return true;
			}
		if (temp == d || temp == a) {
			return true;
		}
		if (temp != 0x20) {
			if (temp != inputRe) {
				break;
			}
		}
		counter2++;
	}

	//controllo diagonali "in basso a sinistra" presenza alfieri o regina o re (aumenta indice verticale  e diminuisce orizzontale)
	int counter3 = re.at(0);
	for (auto i = re.at(1); i >= 0; i--) {
		if (counter3 >= 8) {
			break;
		}
		
		char temp = board.getPiece(counter3, i);
		
		//controllo se il re puo' essere mangiato
		if ((i == re.at(1) - 1) && (counter3 == re.at(0) + 1))
			if (temp == r) {
				return true;
			}
		if (temp == d || temp == a) {
			return true;
		}
		if (temp != 0x20) {
			if (temp != inputRe) {
				break;
			}
		}
		counter3++;
	}

	//controllo diagonali "in alto a destra" presenza alfieri o regina o re (aumenta indice orizzontale e diminuisce vertivale)
	int counter4 = re.at(0);
	for (auto i = re.at(1); i < 8; i++) {
		if (counter4 < 0) {
			break;
		}
		
		char temp = board.getPiece(counter4, i);

		if ((i == re.at(1) + 1) && (counter4 == re.at(0) - 1)) {
			if (temp == r) {
				return true;
			}
		}
		if (temp == d || temp == a) {
			return true;
		}
		if (temp != 0x20) {
			if (temp != inputRe) {
				break;
			}
		}
		counter4--;
	}

	//CONTROLLO SCACCO CAVALLO
	//#1
	if(rangeCheck(re.at(0) + 1, re.at(1) + 2)) {
		if((board.getPiece(re.at(0) + 1, re.at(1) + 2) == c)) {
			return true;
		}
	}
	//#2
	if (rangeCheck(re.at(0) + 2, re.at(1) + 1)) {
		if (board.getPiece(re.at(0) + 2, re.at(1) + 1) == c) {
			return true;
		}
	}
	//#3
	if (rangeCheck(re.at(0) + 1, re.at(1) - 2)) {
		if (board.getPiece(re.at(0) + 1, re.at(1) - 2) == c) {
			return true;
		}
	}
	//#4
	if (rangeCheck(re.at(0) + 2, re.at(1) - 1)) {
		if (board.getPiece(re.at(0) + 2, re.at(1) - 1) == c) {
			return true;
		}
	}
	//#5
	if (rangeCheck(re.at(0) - 1, re.at(1) + 2)) {
		if (board.getPiece(re.at(0) - 1, re.at(1) + 2) == c) {
			return true;
		}
	}
	//#6
	if (rangeCheck(re.at(0) - 2, re.at(1) + 1)) {
		if (board.getPiece(re.at(0) - 2, re.at(1) + 1) == c) {
			return true;
		}
	}
	//#7
	if (rangeCheck(re.at(0) - 1, re.at(1) - 2)) {
		if (board.getPiece(re.at(0) - 1, re.at(1) - 2) == c) {
			return true;
		}
	}
	//#8
	if (rangeCheck(re.at(0) - 2, re.at(1) - 1)) {
		if (board.getPiece(re.at(0) - 2, re.at(1) - 1) == c) {
			return true;
		}
	}

	//Se non trova nessun scacco ritornda FALSE
	return false;
}
