#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "scacchiera.h"
#include "traduttore.h"
#include "middlePieces.h"

std::string randomPosition(std::string, char);
bool rangeCheck(int colonna, int riga);

std::string traduzionePerRandom(int colonna, int riga);