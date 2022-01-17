#include "torre.h"

bool torre::moveTorreCheck(std::string inputMovement) {
	//traduzione degli input da "giocatore umano" a indici array 2D
	std::vector<int> input = traduttore::traduci(inputMovement);

	//movimento verticale o orizzontale:
	//rispettivamente, o la lettera rimane costante e varia il numero, oppure il numero
	//rimane costante e la lettera varia
	if ((input.at(0) == input.at(2) && input.at(1) != input.at(3)) || (input.at(1) == input.at(3) && input.at(0) != input.at(2)))
		return true;

	return false;
}
