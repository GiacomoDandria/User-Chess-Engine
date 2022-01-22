//Autore: Giovanni Bellato

#pragma once
#include<string>
#include "scacchiera.h"
#include "traduttore.h"

struct torre {
	static bool moveTorreCheck(std::string inputMovement); //Controllo validita' mossa della torre
};

