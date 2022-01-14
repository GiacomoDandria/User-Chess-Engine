#include "scacchiera.h"



/*TODO: - aggiungere funzioni di check situazioni speciali subito dopo il move o nel main
        - aggiungere distruttore
        - aggiungere controllo pedone */


//scacchiera per debug funzione di check middle pieces
//scacchiera::scacchiera() : board{
//    {'T', 'C', 'A', 'D', 'R', 'A', 'C', 'T'},
//    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
//    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
//    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
//    { 0x20, 'D', 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
//    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
//    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
//    { 't', 'c', 'a', 'd', 'r', 'a', 'c', 't' },
//} {
//}

scacchiera::scacchiera() : board{
    {'T', 'C', 'A', 'D', 'R', 'A', 'C', 'T'},
    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
    { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
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
    
    // controllo: se la mossa e' l'arrocco faccio un controllo 
    // se non si può fare restituisco false
    if (scacchiera::arroccoCheck(fromLetter, fromNumber, toLetter, toNumber)) {
        return true;            //arrocco fatto
    }
    
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
        else {
            if (frompiece == 'r')
                r = true;
            else
                R = true;
        }
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
        else {
            //modifico il bool per l'ARROCCO
            if (frompiece == 't')
                if (fromLetter == 0 && fromNumber == 7)
                    t1 = true;
                else
                    t2 = true;
            else {
                if (fromLetter == 0 && fromNumber == 0)
                    T1 = true;
                else
                    T2 = true;
            }
        }
    }
    else if (frompiece == 'p' || frompiece == 'P') {
        if (!scacchiera::pedoneCheck(position, frompiece, topiece))
            return false;
    }

    //parte MOVE
    board[toNumber][toLetter] = board[fromNumber][fromLetter];
    board[fromNumber][fromLetter] = 0x20;

    //Controllo promozione
    scacchiera::promozioneCheck();

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
        else if (((input.at(2) == input.at(0) + 1) || (input.at(2) == input.at(0) - 1)) && (input.at(3) == input.at(1) + 1) && (topiece != 0x20))
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
        else if (((input.at(2) == input.at(0) + 1) || (input.at(2) == input.at(0) - 1)) && (input.at(3) == input.at(1) - 1) && (topiece != 0x20)){}
        else if (((input.at(2) == input.at(0) + 1) || (input.at(2) == input.at(0) - 1)) && (input.at(3) == input.at(1) - 1))
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

//stampa la scacchiera a video
void scacchiera::printScacchieraVideo()
{
    int counter = 8;
    for (auto i = 0; i < 8; i++) {
        std::cout << counter << " ";
        for (auto j = 0; j < 8; j++)
        {
            std::cout << board[i][j];
        }
        counter--;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "  ABCDEFGH";
    std::cout << "/n" << "/n" << "/n";
    Sleep(1000000);
}

//stampa la scacchiera su file
void scacchiera::printScacchieraFile(std::string outputFile)
{
    std::fstream fileWriter;
    fileWriter.open(outputFile, std::fstream::out);
    int counter = 8;
    for (auto i = 0; i < 8; i++) {
        fileWriter << counter << " ";
        for (auto j = 0; j < 8; j++)
        {
            fileWriter << board[i][j];
        }
        counter--;
        fileWriter << std::endl;
    }
    fileWriter << std::endl;
    fileWriter << "  ABCDEFGH";
    fileWriter << "\n\n\n";
    fileWriter.close();
}
//Promozione dei perdoni 
void scacchiera::promozioneCheck() {
    // Contro riga 8 (sopra). i e' l'indice delle colonne 
    for (int i = 0; i < 8; i++) {
        if(getPiece(0,i)== 'p')
            board[0][i] = 'd';
    }
    // Contro riga 1 (sotto). i e' l'indice delle colonne
    for (int i = 0; i < 8; i++) {
        if (getPiece(7, i) == 'P')
            board[7][i] = 'D';
    }
}


//--ARROCCO--
//Ritorna true se la mossa di arrocco e' stata effettuata
bool scacchiera::arroccoCheck(int fromLetter, int fromNumber, int toLetter, int toNumber) {
    //BIANCHI
    //#1 Caso arrocco con torre di sinistra 
    if ((fromLetter == 4 && toLetter == 0 && fromNumber == 7 && toNumber == 7) ||
        (fromLetter == 0 && toLetter == 4 && fromNumber == 7 && toNumber == 7)) {
        if (t1 == false && r == false) //PEDINE NON MOSSE 
            if (board[7][1] == 0x20 &&
                board[7][2] == 0x20 &&
                board[7][3] == 0x20) 
            {
                board[7][2] = 'r';
                board[7][3] = 't';
                board[7][0] = 0x20;
                board[7][4] = 0x20;
                return true;
            }
                
    }
    //#2 Caso arrocco con torre a destra
    if ((fromLetter == 4 && toLetter == 7 && fromNumber == 7 && toNumber == 7) ||
        (fromLetter == 7 && toLetter == 4 && fromNumber == 7 && toNumber == 7)) {
        if (t2 == false && r == false) //PEDINE NON MOSSE 
            if (board[7][6] == 0x20 &&
                board[7][5] == 0x20 )
            {
                board[7][6] = 'r';
                board[7][5] = 't';
                board[7][4] = 0x20;
                board[7][7] = 0x20;
                return true;
            }

    }
    //NERI
    //#1 Caso arrocco con torre di sinistra 
    if ((fromLetter == 4 && toLetter == 0 && fromNumber == 0 && toNumber == 0) ||
        (fromLetter == 0 && toLetter == 4 && fromNumber == 0 && toNumber == 0)) {
        if (T1 == false && R == false) //PEDINE NON MOSSE 
            if (board[0][1] == 0x20 &&
                board[0][2] == 0x20 &&
                board[0][3] == 0x20)
            {
                board[0][2] = 'R';
                board[0][3] = 'T';
                board[0][0] = 0x20;
                board[0][4] = 0x20;
                return true;
            }

    }
    //#2 Caso arrocco con torre a destra
    if ((fromLetter == 4 && toLetter == 7 && fromNumber == 0 && toNumber == 0) ||
        (fromLetter == 7 && toLetter == 4 && fromNumber == 0 && toNumber == 0)) {
        if (T2 == false && R == false) //PEDINE NON MOSSE 
            if (board[0][6] == 0x20 &&
                board[0][5] == 0x20)
            {
                board[0][6] = 'R';
                board[0][5] = 'T';
                board[0][4] = 0x20;
                board[0][7] = 0x20;
                return true;
            }

    }
    return false;
}

