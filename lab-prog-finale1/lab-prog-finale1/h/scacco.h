#pragma once
#include "scacchiera.h"
#include "middlePieces.h"
#include "randomMoves.h"
#include<string>
#include<vector>


struct scacco {
	//check dello scacco (BASE)
	static bool check(scacchiera & board, char re);
	//check dello scacco (PER SCACCO MATTO)
	static bool checkTwo(scacchiera & board, char inputRe, int inColonna, int inRiga);
};