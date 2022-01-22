//Autore: Giovanni Bellato

#include "torre.h"

bool torre::moveTorreCheck(std::string inputMovement)
{
	//traduzione degli input da "giocatore umano" a indici matrice
	std::vector<int> input = traduttore::traduci(inputMovement); 

	/*Controllo se sono eseguite dei movimenti validi ovvero: verticale e orrizzontale. 
	  -Stessa riga ma varia la colonna (ORRIZZONTALE)
	  -Stessa colonna ma varia la riga (VERTICALE)    
	*/

	if ((input.at(0) == input.at(2) && input.at(1) != input.at(3)) || (input.at(1) == input.at(3) && input.at(0) != input.at(2)))
	{
		return true;
	}
	return false;
}
