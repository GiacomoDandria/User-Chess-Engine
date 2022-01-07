#include "middlePieces.h"

/*TODO: - finire funzioni di check*/

/*controllo che le caselle attraverso le quali una pediana si vuole muovere siano effettivamente vuote*/

bool middlePieces::check(scacchiera& board, int fromLetter, int fromNumber, int toLetter, int toNumber) {
	//controllo che le posizioni della scacchiera tra quella di partenza e quella di arrivo siano vuote
	//caso 1: lettera di partenza uguale a quella di arrivo: movimento in verticale
	if (fromLetter == toLetter) {
		for (auto i = std::min(fromNumber, toNumber); i <= std::max(fromNumber, toNumber); i++) {
			if (board.getPiece(i, fromLetter) != 0x20) {
				//std::cout << "fromletter==toletter" << std::endl;
				return false;
			}
		}
	}

	//caso 2: numero di partenza uguale a quello di arrivo: movimento in orizzontale
	if (fromNumber == toNumber) {
		for (auto i = std::min(fromLetter, toLetter); i <= std::max(fromLetter, toLetter); i++) {
			if (board.getPiece(i, fromNumber) != 0x20) {
				//std::cout << "fromnumber==tonumber" << std::endl;
				return false;
			}
		}
	}

	//caso 3: numero di spostamenti nella direzione verticale è uguale a quello in orizzontale: movimento obliquo
	if (std::abs(toLetter - fromLetter) == std::abs(toNumber - fromNumber)) {
		//caso 3.1: movimento nella direzione in basso-destra
		if (toLetter > fromLetter && toNumber > fromNumber) {
			int temp = fromNumber;
			for (auto i = fromLetter; i <= toLetter; i++) {
				fromNumber += 1;
				if (board.getPiece(i, fromNumber) != 0x20)
					return false;
			}
		}
		//caso 3.2: movimento in direzione in alto-destra
		if (toLetter > fromLetter && toNumber < fromNumber) {
			int temp = fromNumber;
			for (auto i = fromLetter; i >= toLetter; i--) {
				fromNumber += 1;
				if (board.getPiece(i, fromNumber) != 0x20)
					return false;
			}
		}
		//caso 3.3: movimento in direzione in basso-sinistra
		if (toLetter < fromLetter && toNumber > fromNumber) {
			int temp = fromNumber;
			for (auto i = fromLetter; i <= toLetter; i++) {
				fromNumber -= 1;
				if (board.getPiece(i, fromNumber) != 0x20)
					return false;
			}
		}
		//caso 3.4: movimento in direzione in alto-sinistra
		if (toLetter < fromLetter && toNumber < fromNumber) {
			int temp = fromNumber;
			for (auto i = fromLetter; i >= toLetter; i--) {
				fromNumber -= 1;
				if (board.getPiece(i, fromNumber) != 0x20)
					return false;
			}
		}
	}
	return true;
}

