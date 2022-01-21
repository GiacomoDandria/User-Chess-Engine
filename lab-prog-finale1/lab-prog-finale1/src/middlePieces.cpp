#include "middlePieces.h"

bool middlePieces::check(scacchiera& board, int fromLetter, int fromNumber, int toLetter, int toNumber) {
	//controllo che le posizioni della scacchiera tra quella di partenza e quella di arrivo siano vuote

	//caso 1: lettera di partenza uguale a quella di arrivo: movimento in verticale
	if (fromLetter == toLetter) {
		//caso 1.1: movimento verticale verso il basso
		if (fromNumber < toNumber) {
			for (auto i = fromNumber + 1; i < toNumber; i++) {
				if (board.getPiece(i, fromLetter) != 0x20) {
					return false;
				}	
			}
		}
		//caso 1.2: movimento verticale verso l'alto
		else if (fromNumber > toNumber) {
			for (auto i = fromNumber - 1; i > toNumber; i--) {
				if (board.getPiece(i, fromLetter) != 0x20) {
					return false;
				}
			}
		}
	}
	
	//caso 2: numero di partenza uguale a quello di arrivo: movimento in orizzontale
	if (fromNumber == toNumber) {
		//caso 2.1: movimento orizzontale verso destra
		if (fromLetter < toLetter) {
			for (auto i = fromLetter + 1; i < toLetter; i++) {
				if (board.getPiece(fromNumber, i) != 0x20) {
						return false;
				}
			}
		}
		//caso 2.2: movimento orizzontale verso sinistra
		else if (fromLetter > toLetter) {
			for (auto i = fromLetter - 1; i > toLetter; i--) {
				if (board.getPiece(fromNumber, i) != 0x20) {
						return false;
				}
			}
		}
	}
	
	//caso 3: numero di spostamenti nella direzione verticale è uguale a quello in orizzontale: movimento obliquo
	if (std::abs(toLetter - fromLetter) == std::abs(toNumber - fromNumber)) {
		//caso 3.1: movimento nella direzione in basso-destra
		if (toLetter > fromLetter && toNumber > fromNumber) {
			int temp = fromNumber + 1;
			for (auto i = fromLetter + 1; i < toLetter; i++) {
				fromNumber += 1;
				if (board.getPiece(fromNumber, i) != 0x20) {
					return false;
				}
			}
		}
		//caso 3.2: movimento in direzione in alto-destra
		if (toLetter > fromLetter && toNumber < fromNumber) {
			for (auto i = fromLetter + 1; i < toLetter; i++) {
				fromNumber -= 1;
				if (board.getPiece(fromNumber, i) != 0x20) {
					return false;
				}
			}
		}
		//caso 3.3: movimento in direzione in basso-sinistra
		if (toLetter < fromLetter && toNumber > fromNumber) {
			for (auto i = fromLetter - 1; i > toLetter; i--) {
				fromNumber += 1;
				if (board.getPiece(fromNumber, i) != 0x20) {
					return false;
				}
			}
		}
		//caso 3.4: movimento in direzione in alto-sinistra
		if (toLetter < fromLetter && toNumber < fromNumber) {
			for (auto i = fromLetter - 1; i > toLetter; i--) {
				fromNumber -= 1;
				if (board.getPiece(fromNumber, i) != 0x20) {
					return false;
				}
			}
		}
	}
	return true;
}
