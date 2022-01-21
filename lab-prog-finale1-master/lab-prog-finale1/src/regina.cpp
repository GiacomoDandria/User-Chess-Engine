//Autore: Giacomo D'Andria

#include "regina.h"

bool regina::moveReginaCheck(std::string inputMovement) {
	//traduzione degli input da "giocatore umano" a indici array 2D
	std::vector<int> input = traduttore::traduci(inputMovement);

	//il movimento della regina e' composto da quello dell'alfiere o quello della torre - ma non entrambi contemporaneamente
	//dunque, nei diversi casi, bisogna controllare che:
	//	- la lettera rimanga la stessa e cambi solo il numero -> movimento verticale
	//	- il numero rimanga lo stesso e cambi solo la lettera -> movimento orizzontale
	//	- lettera e numero cambino, in valore assoluto, della stessa quantita' -> moviemnto obliquo
	if ((std::abs(input.at(2) - input.at(0)) == std::abs(input.at(3) - input.at(1))) ||
		(input.at(0) == input.at(2) && input.at(1) != input.at(3)) || (input.at(1) == input.at(3) && input.at(0) != input.at(2))) {
		return true;
	}
	return false;
}
