#include"scacco.h"

bool scacco::check(scacchiera board, char inputRe) {
	char t, c, a, d, r, p;

	if (inputRe == 'R') {
		t = 't';
		c = 'c';
		a = 'a';
		d = 'd';
		r = 'r';
		p = 'p';
	}
	else if (inputRe = 'r') {
		t = 'T';
		c = 'C';
		a = 'A';
		d = 'D';
		r = 'R';
		p = 'P';
	}
	
	std::vector<int> re = board.findRe(inputRe);
	/*std::cout << "Tipo pedine: " << a << std::endl;
	std::cout << "Posizione re: " << re.at(0) << re.at(1) << std::endl;*/

	//controllo verticale delle pedine presenti "sotto" il re
	for (auto i = re.at(0); i < 8; i++) {
		char temp = board.getPiece(i, re.at(1));
		//std::cout << "Temp-sotto-re: " << temp << std::endl;
		if (temp == d || temp == t) {
			/*std::cout << "Pedina che sta facendo scacco: " << temp << std::endl;
			std::cout << "scacco verticale sotto D-d o T-t" << std::endl;*/
			return true;
		}
		if (temp == p || temp == r || temp == a || temp == c) {
			break;
		}
	}

	//std::cout << "1: checked" << std::endl;

	//controllo verticale delle pedine presenti "sopra" il re
	for (auto i = re.at(0); i >= 0; i--) {
		//std::cout << "soafijaiof: " << board.getPiece(4, 1) << std::endl;
		char temp = board.getPiece(i, re.at(1));
		//std::cout << "Temp-sopra-re: " << temp << std::endl;
		if (temp == d || temp == t) {
			/*std::cout << "Pedina che sta facendo scacco: " << temp << std::endl;
			std::cout << "scacco verticale sopra D-d o T-t" << std::endl;*/
			return true;
		}
		else if (temp == p || temp == r || temp == a || temp == c) {
			break;
		}
	}

	//std::cout << "2: checked" << std::endl;

	//controllo orizzontale "sinistro" pedine presenti
	for (auto i = re.at(1); i >= 0; i--) {
		char temp = board.getPiece(re.at(0), i);
		//std::cout << "Temp-sinistro-re: " << temp << std::endl;
		if (temp == d || temp == t) {
			/*std::cout << "Pedina che sta facendo scacco: " << temp << std::endl;
			std::cout << "scacco orizzontale sinistro D-d o T-t" << std::endl;*/
			return true;
		}
		else if (temp == p || temp == r || temp == a || temp == c) {
			break;
		}
	}

	//std::cout << "3: checked" << std::endl;

	//controllo orizzontale "destro" pedine presenti
	for (auto i = re.at(1); i < 8; i++) {
		char temp = board.getPiece(re.at(0), i);
		//std::cout << "Temp-destro-re: " << temp << std::endl;
		if (temp == d || temp == t) {
			/*std::cout << "Pedina che sta facendo scacco: " << temp << std::endl;
			std::cout << "scacco orizzontale destro D-d o T-t" << std::endl;*/
			return true;
		}
		else if (temp == p || temp == r || temp == a || temp == c) {
			break;
		}
	}

	//std::cout << "4: checked" << std::endl;

	//controllo obliquo presenza pedoni, divide il controllo nel caso di pedine maiuscole e minuscole perché i pedoni
	//possono soltanto "andare avanti" nella scacchiera
	if (inputRe == 'R') { //check per pedine maiuscole
		if ((board.getPiece(re.at(0) + 1, re.at(1) + 1) == p) || (board.getPiece(re.at(0) + 1, re.at(1) - 1) == p)) {
			//std::cout << "scacco pedone1" << std::endl;
			return true;
		}
	}
	else if (inputRe == 'r') { //check per pedine minuscole
		if ((board.getPiece(re.at(0) - 1, re.at(1) - 1) == p) || (board.getPiece(re.at(0) - 1, re.at(1) + 1) == p)) {
			//std::cout << "scacco pedone2" << std::endl;
			return true;
		}
	}

	//std::cout << "5: checked" << std::endl;

	//controllo diagonali "in alto a sinistra" presenza alfieri o regina (diminuiscono entrambi gli indici)-------------------------------------------
	int counter1 = re.at(1);
	for (auto i = re.at(0); i >= 0; i--) {
		if (counter1 < 0) {
			break;
		}
		char temp = board.getPiece(i, counter1);
		//std::cout << "Temp-alto-sx: " << temp << std::endl;
		if (temp == d || temp == a) {
			/*std::cout << "Pedina che sta facendo scacco: " << temp << std::endl;
			std::cout << "scacco diagonali in alto a sx D-d o A-a" << std::endl;*/
			return true;
		}
		else if (temp == p || temp == r || temp == t || temp == c) {
			break;
		}
		counter1--;
	}

	//std::cout << "6: checked" << std::endl;

	//controllo diagonali "in basso a destra" presenza alfieri o regina (aumentano entrambi gli indici)
	int counter2 = re.at(1);
	for (auto i = re.at(0); i < 8; i++) {
		if (counter2 >= 8) {
			break;
		}
		char temp = board.getPiece(i, counter2);
		//std::cout << "Temp-basso-dx: " << temp << std::endl;
		if (temp == d || temp == a) {
			/*std::cout << "Pedina che sta facendo scacco: " << temp << std::endl;
			std::cout << "scacco diagonali in basso a dx D-d o A-a" << std::endl;*/
			return true;
		}
		else if (temp == p || temp == r || temp == t || temp == c) {
			break;
		}
		counter2++;
	}

	//std::cout << "7: checked" << std::endl;

	//controllo diagonali "in basso a sinistra" presenza alfieri o regina (aumenta indice verticale  e diminuisce orizzontale)
	int counter3 = re.at(0);
	for (auto i = re.at(1); i > 0; i--) {
		if (counter3 >= 8) {
			break;
		}
		char temp = board.getPiece(counter3, i);
		//std::cout << "Temp-basso-sx: " << temp << std::endl;
		if (temp == d || temp == a) {
			/*std::cout << "Pedina che sta facendo scacco: " << temp << std::endl;
			std::cout << "scacco diagonali in basso a sx D-d o A-a" << std::endl;*/
			return true;
		}
		else if (temp == p || temp == r || temp == t || temp == c) {
			break;
		}
		counter3++;
	}

	//std::cout << "8: checked" << std::endl;

	//controllo diagonali "in alto a destra" presenza alfieri o regina (aumenta indice orizzontale e diminuisce vertivale)
	int counter4 = re.at(0);
	for (auto i = re.at(1); i < 8; i++) {
		if (counter4 < 0) {
			break;
		}
		char temp = board.getPiece(counter4, i);
		//std::cout << "Temp-alto-dx: " << temp << std::endl;
		if (temp == d || temp == a) {
			/*std::cout << "Pedina che sta facendo scacco: " << temp << std::endl;
			std::cout << "scacco diagonali in alto a dx D-d o A-a" << std::endl;*/
			return true;
		}
		else if (temp == p || temp == r || temp == t || temp == c) {
			break;
		}
		counter4--;
	}
	
	//std::cout << "9: checked" << std::endl;

	/*controllo presenza cavallo--RESTITUISCE RISPOSTE SBAGLIATE SE GLI INDICI VANNO FUORI DAL RANGE DELLA MATRICE
	per esempio, con il re in posizione (y=4, x=7) std::cout << "sdofisdhoi " << board.getPiece(re.at(0) - 1, re.at(1) + 2) << std::endl
	restituisce che e' presente una 'C' in tale posizione, anche se gli indici sono fuori dalla matrice*/
	
	
	//CONTROLLO SCACCO CAVALLO
	//if ((board.getPiece(re.at(0) + 1, re.at(1) + 2) == c) ||
	//	(board.getPiece(re.at(0) + 2, re.at(1) + 1) == c) ||
	//	(board.getPiece(re.at(0) + 1, re.at(1) - 2) == c) ||
	//	(board.getPiece(re.at(0) + 2, re.at(1) - 1) == c) ||
	//	(board.getPiece(re.at(0) - 1, re.at(1) + 2) == c) ||
	//	(board.getPiece(re.at(0) - 2, re.at(1) + 1) == c) ||
	//	(board.getPiece(re.at(0) - 1, re.at(1) - 2) == c) ||
	//	(board.getPiece(re.at(0) - 2, re.at(1) - 1) == c)) {
	//	//std::cout << "scacco cavallo" << std::endl;
	//	return true;
	//}
	
	return false;
}

