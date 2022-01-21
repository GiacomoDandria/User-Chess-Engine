//Autore: Giovanni Bellato

#include "alfiere.h"

bool alfiere::moveAlfiereCheck(std::string inputMovement) 
{
	//traduzione degli input da "giocatore umano" a indici array 2D
	std::vector<int> input = traduttore::traduci(inputMovement);

	/*utilizzare il valore assoluto del cambiamento perche' nei movimenti verso alto-dx e basso-sx gli indici
	  della matrice cambiano di segno ma devono comunque essere uguali in modulo per poter verificare che
	  il movimento sia effettivamente diagonale
	*/
	if(std::abs(input.at(2) - input.at(0)) == std::abs(input.at(3) - input.at(1)))
	{
		return true;
	}
	return false;
}

