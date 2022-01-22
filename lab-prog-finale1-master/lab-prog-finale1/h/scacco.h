//Autore: Giacomo D'Andria

#pragma once
#include "scacchiera.h"
#include "middlePieces.h"
#include "randomMoves.h"
#include<string>
#include<vector>


struct scacco {
	//check dello scacco
	static bool check(scacchiera & board, char re, int inColonna, int inRiga);

};
