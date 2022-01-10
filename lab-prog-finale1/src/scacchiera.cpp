#include "scacchiera.h"



/*TODO: - aggiungere funzioni di check situazioni speciali subito dopo il move o nel main
        - aggiungere distruttore
        - aggiungere controllo pedone */


//scacchiera per debug funzione di check scacco
//scacchiera::scacchiera() : board{
//    {'T', 'C', 'A', 'D', 0x20, 'A', 'C', 'T'},
//    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
//    { 0x20, 'A', 'a', 0x20, 'T', 'T', 'a', 0x20},
//    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
//    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 'A', 0x20},
//    { 0x20, 0x20, 'A', 0x20, 0x20, 0x20, 0x20, 0x20},
//    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
//    { 't', 'c', 'a', 'd', 0x20, 'a', 'c', 't'},
//} {
//}

scacchiera::scacchiera() : board{
    {'T', 'C', 'A', 'D', 'R', 'A', 'C', 'T'},
    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
    { 't', 'c', 'a', 'd', 'r', 'a', 'c', 't' },
} {
}
/*Nella funzione movePedina della classe scacchiera, prima della mossa vengono eseguiti i controlli
  necessari ad evitare sovrapposizioni di pedine della stessa squadra e di mosse valide. Per fare
  questo utilizzo i check delle pedine, riconoscendone il tipo tramite la funzione getPiece. Quando
  la mossa sara' esegita correttamente, la funzione ritornera' TRUE   */

bool scacchiera::movePedina(int fromLetter, int fromNumber, int toLetter, int toNumber) {
    //controllo che le posizioni siano valide
    if (fromLetter < 0 || fromNumber < 0 || toLetter < 0 || toNumber < 0)
        return false;

    char frompiece = scacchiera::board[fromNumber][fromLetter];
    char topiece = scacchiera::board[toNumber][toLetter];
    std::string position = traduttore::traduciReverse(fromLetter, fromNumber, toLetter, toNumber);

    //PRIMO controllo: la posizione non varia
    if ((fromLetter == toLetter) && (fromNumber == toNumber))
        return false;
    
    //SECONDO controllo: il pezzo sovrascrive uno dello stesso colore

    if (((frompiece >= 94) && (topiece >= 94)) || ((frompiece < 94) && (frompiece > 32) && (topiece < 94) &&
        (topiece > 32)))
    {
        return false;
    }

    //TERZO controllo: mossa valida per la pedina mossa (tramite check)
    if (frompiece == 'c' || frompiece == 'C') {         //check cavallo
        if (!cavallo::moveCavalloCheck(position))
            return false;
    }
    else if (frompiece == ' ')
        return false;
    else if (frompiece == 'r' || frompiece == 'R') {
        if (!re::moveReCheck(position))
            return false;
    }
    else if (frompiece == 'a' || frompiece == 'A') {
        if (!alfiere::moveAlfiereCheck(position))
            return false;
    }
    else if (frompiece == 'd' || frompiece == 'D') {
        if (!regina::moveReginaCheck(position))
            return false;
    }
    else if (frompiece == 't' || frompiece == 'T') {
        if (!torre::moveTorreCheck(position))
            return false;
    }
    else if (frompiece == 'p' || frompiece == 'P') {
        if (!scacchiera::pedoneCheck(position, frompiece, topiece))
            return false;
    }
    
    //parte MOVE
    board[toNumber][toLetter] = board[fromNumber][fromLetter];
    board[fromNumber][fromLetter] = 0x20;

    return true;
}

void scacchiera::printScacchiera() {
    int counter = 8;
    for (auto i = 0; i < 8; i++) {
        std::cout << counter << " ";
        for (auto j = 0; j < 8; j++) {
            std::cout << board[i][j];
        }
        counter--;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "  ABCDEFGH";
}

char scacchiera::getPiece(int vert, int orizz) {
    return scacchiera::board[vert][orizz];

}

std::vector<int> scacchiera::findRe(char re) {
    std::vector<int> posizioneRe;
    for (auto i = 0; i < 8; i++) {
        for (auto j = 0; j < 8; j++) {
            if (board[i][j] == re) {
                posizioneRe.push_back((int)i);
                posizioneRe.push_back((int)j);
                
            }
        }
    }
    return posizioneRe;
}
//Controllo presenza re per verificare la vittoria
bool scacchiera::checkWin(char re) {
    for (auto i = 0; i < 8; i++) {
        for (auto j = 0; j < 8; j++) {
            if (board[i][j] == re) {
                return false;
            }
        }
    }
    return true;
}

//-------------------
// PEDONE CHECK
//-------------------

bool scacchiera::pedoneCheck( std::string position, char frompiece, char topiece) {
    //controlli precondizioni della stringa di input
    if (position.length() != 5)
    {
        return false;
    }

    //traduzione degli input da "giocatore umano" a indici array 2D
    std::vector<int> input = traduttore::traduci(position);

    if (frompiece == 'P')
    {
        //SIMPLE FORWARD MOVEMENT
        if ((input.at(0) == input.at(2)) && (input.at(3) == input.at(1) + 1) && (topiece == 0x20))
        {
            return true;
        }
        //OBLIQUE EATING MOVEMENT
        else if ((input.at(2) == input.at(0) + 1) || (input.at(2) == input.at(0) - 1) && (input.at(3) == input.at(1) + 1))
        {
            return true;
        }
        //DOUBLE BOX MOVEMENT
        else if ((input.at(1) == 1) && (input.at(3) == 3) && (topiece == 0x20))
        {
            return true;
        }
        return false;
    }
    if (frompiece == 'p')
    {
        //SIMPLE FORWARD MOVEMENT
        if ((input.at(0) == input.at(2)) && (input.at(3) == input.at(1) - 1) && (topiece == 0x20))
        {
            return true;
        }
        //OBLIQUE EATING MOVEMENT
        else if ((input.at(2) == input.at(0) + 1) || (input.at(2) == input.at(0) - 1) && (input.at(3) == input.at(1) - 1))
        {
            return true;
        }
        //DOUBLE BOX MOVEMENT
        else if ((input.at(1) == 6) && (input.at(3) == 4) && (topiece == 0x20))
        {
            return true;
        }
        return false;
    }
    return false;
}




