#include "middlePieces.h"

/*TODO: - finire funzioni di check*/

/*controllo che le caselle attraverso le quali una pediana si vuole muovere siano effettivamente vuote*/

bool middlePieces::check(scacchiera& board, int fromLetter, int fromNumber, int toLetter, int toNumber) {
	//controllo che le posizioni della scacchiera tra quella di partenza e quella di arrivo siano vuote

	//caso 1: lettera di partenza uguale a quella di arrivo: movimento in verticale--FUNZIONA
	if (fromLetter == toLetter) {
		//caso 1.1: movimento verticale verso il basso
		if (fromNumber < toNumber) {
			for (auto i = fromNumber + 1; i <= toNumber; i++) {
			std::cout << "asfoadifjsioad: " << board.getPiece(i, fromLetter) << std::endl;
				if (board.getPiece(i, fromLetter) != 0x20) {
					std::cout << "fromletter==toletter-verticale-verso-basso" << std::endl;
					return false;
				}
			}
		}
		//caso 1.2: movimento verticale verso l'alto
		else if (fromNumber > toNumber) {
			for (auto i = fromNumber - 1; i >= toNumber; i--) {
			std::cout << "asfoadifjsioad: " << board.getPiece(i, fromLetter) << std::endl;
				if (board.getPiece(i, fromLetter) != 0x20) {
					std::cout << "fromletter==toletter-verticale-verso-alto" << std::endl;
					return false;
				}
			}
		}
	}
	
	//caso 2: numero di partenza uguale a quello di arrivo: movimento in orizzontale--FUNZIONA
	if (fromNumber == toNumber) {
		//caso 2.1: movimento orizzontale verso destra
		if (fromLetter < toLetter) {
			for (auto i = fromLetter + 1; i <= toLetter; i++) {
			std::cout << "asfoadifjsioad: " << board.getPiece(fromNumber, i) << std::endl;
				if (board.getPiece(fromNumber, i) != 0x20) {
					std::cout << "fromnumber==tonumber-verso-destra" << std::endl;
						return false;
				}
			}
		}
		//caso 2.2: movimento orizzontale verso sinistra
		else if (fromLetter > toLetter) {
			for (auto i = fromLetter - 1; i >= toLetter; i--) {
			std::cout << "asfoadifjsioad: " << board.getPiece(fromNumber, i) << std::endl;
				if (board.getPiece(fromNumber, i) != 0x20) {
					std::cout << "fromnumber==tonumber-verso-sinistra" << std::endl;
						return false;
				}
			}
		}
	}
	
	//caso 3: numero di spostamenti nella direzione verticale è uguale a quello in orizzontale: movimento obliquo
	if (std::abs(toLetter - fromLetter) == std::abs(toNumber - fromNumber)) {

		//caso 3.1: movimento nella direzione in basso-destra--FUNZIONA
		if (toLetter > fromLetter && toNumber > fromNumber) {
			int temp = fromNumber + 1;
			for (auto i = fromLetter + 1; i <= toLetter; i++) {
				fromNumber += 1;
				std::cout << "asofiajfioa: " << board.getPiece(fromNumber, i) << std::endl;
				if (board.getPiece(fromNumber, i) != 0x20) {
					std::cout << "toLetter > fromLetter && toNumber > fromNumber" << std::endl;
					return false;
				}
			}
		}
		//caso 3.2: movimento in direzione in alto-destra--FUNZIONA
		if (toLetter > fromLetter && toNumber < fromNumber) {
			std::cout << "dasofijasofjiasofjasoifjaisdioasjdiaso" << std::endl;
			//int temp = fromNumber;
			std::cout << "From letter: " << fromLetter << std::endl;
			std::cout << "From number: " << fromNumber << std::endl;
			std::cout << "To letter: " << toLetter << std::endl;
			std::cout << "To number: " << toNumber << std::endl;


			for (auto i = fromLetter + 1; i <= toLetter; i++) {
				fromNumber -= 1;
				std::cout << "asofiajfioa: " << board.getPiece(fromNumber, i) << std::endl;
				if (board.getPiece(fromNumber, i) != 0x20) {
					std::cout << "toLetter > fromLetter && toNumber < fromNumber" << std::endl;
					return false;
				}
			}
		}
		//caso 3.3: movimento in direzione in basso-sinistra--FUNZIONA
		if (toLetter < fromLetter && toNumber > fromNumber) {
			std::cout << "dasofijasofjiasofjasoifjaisdioasjdiaso" << std::endl;
			//int temp = fromNumber;
			std::cout << "From letter: " << fromLetter << std::endl;
			std::cout << "From number: " << fromNumber << std::endl;
			std::cout << "To letter: " << toLetter << std::endl;
			std::cout << "To number: " << toNumber << std::endl;
			for (auto i = fromLetter - 1; i >= toLetter; i--) {
				fromNumber += 1;

				std::cout << "asofiajfioa: " << board.getPiece(fromNumber, i) << std::endl;
				if (board.getPiece(fromNumber, i) != 0x20) {
					std::cout << "toLetter < fromLetter && toNumber > fromNumber" << std::endl;
					return false;
				}
			}
		}
		//caso 3.4: movimento in direzione in alto-sinistra--FUNZIONA
		if (toLetter < fromLetter && toNumber < fromNumber) {
			std::cout << "dasofijasofjiasofjasoifjaisdioasjdiaso" << std::endl;
			//int temp = fromNumber;
			std::cout << "From letter: " << fromLetter << std::endl;
			std::cout << "From number: " << fromNumber << std::endl;
			std::cout << "To letter: " << toLetter << std::endl;
			std::cout << "To number: " << toNumber << std::endl;
			for (auto i = fromLetter - 1; i >= toLetter; i--) {
				fromNumber -= 1;
				std::cout << "asofiajfioa: " << board.getPiece(fromNumber, i) << std::endl;
				if (board.getPiece(fromNumber, i) != 0x20) {
					std::cout << "toLetter < fromLetter && toNumber < fromNumber" << std::endl;
					return false;
				}
			}
		}
	}
	return true;
}

