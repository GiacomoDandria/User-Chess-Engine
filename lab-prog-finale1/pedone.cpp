#include "pedone.h"

/*TODO: - controllare che il pednoe non possa mangiare andando avanti, ma solo di lato.
		  Lanciare eccezione se si vuole muovere avanti in una casella occupata */

bool pedone::movePedoneCheck(std::string inputMovement)
{
	////controlli precondizioni della stringa di input
	//if (inputMovement.length() != 5)
	//{
	//	return false;
	//}
	//
	//////traduzione degli input da "giocatore umano" a indici array 2D
	////std::vector<int> input = traduttore::traduci(inputMovement);
	////
	////if(board.getPiece(input.at(0), input.at(1)) == "P")
	////{
	////	//SIMPLE FORWARD MOVEMENT
	////	if (input.at(0) == input.at(2) && input.at(3) == input.at(1) + 1 && board.getPiece(input.at(2), input.at(3)) == 0x20)
	////	{
	////		return true;
	////	}
	////	//OBLIQUE EATING MOVEMENT
	////	else if ((input.at(2) == input.at(0) + 1 || input.at(2) == input.at(0) - 1) && input.at(3) == input.at(1) + 1) 
	////	{
	////		return true;
	////	}
	////	//DOUBLE BOX MOVEMENT
	////	else if(input.at(1) == 1 && input.at(3) == 3 && board.getPiece(input.at(2), input.at(3)) == 0x20)
	////	{
	////		return true;
	////	}
	////	return false;
	////}
	////if(board.getPiece(input.at(0), input.at(1)) == "p")
	////{
	////	//SIMPLE FORWARD MOVEMENT
	////	if (input.at(0) == input.at(2) && input.at(3) == input.at(1) - 1 && board.getPiece(input.at(2), input.at(3)) == 0x20) 
	////	{
	////		return true;
	////	}
	////	//OBLIQUE EATING MOVEMENT
	////	else if ((input.at(2) == input.at(0) + 1 || input.at(2) == input.at(0) - 1) && input.at(3) == input.at(1) - 1) 
	////	{
	////		return true;
	////	}
	////	//DOUBLE BOX MOVEMENT
	////	else if(input.at(1) == 6 && input.at(3) == 4 && board.getPiece(input.at(2), input.at(3)) == 0x20)
	////	{
	////		return true;
	////	}
	////	return false;
	////}
	return false;
}