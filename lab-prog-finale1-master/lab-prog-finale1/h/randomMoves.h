//AUTORE: MARCO SQUARCINA

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "scacchiera.h"
#include "traduttore.h"
#include "middlePieces.h"

std::string randomMove(scacchiera & ,std::string, char);    //Ritorna delle coordinate random data una certa pedina

bool rangeCheck(int colonna, int riga);                     //Controllo coordinate dentro i range della scacchiera

bool friendlyCheckU(scacchiera&, int colonna, int riga);    //Controllo se la pedina , date le coordinate, e' maiuscola
                                                            // U sta per UpperCase
bool friendlyCheckL(scacchiera&, int colonna, int riga);    //Controllo se la pedina , date le coordinate, e' minuscola 
                                                            //L sta per LowerCase
bool someone(scacchiera&, int colonna, int riga);           //Controlla se e' presente una pedina date certe coordinate 

std::string traduzionePerRandom(int colonna, int riga);     //E' una traduzione piu' specifica da coordinate a stringa
