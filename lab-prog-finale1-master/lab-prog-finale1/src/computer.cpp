#include"computer.h"

computer::computer(){throw NoCorrectInfoConstructor();}   //costruttore vuoto

computer::computer(char c) {                       //costruttore pedine white o black
    //se bianche
    if (c == 'w')
    {
        computer::coordinate.push_back("A1");
        computer::coordinate.push_back("A2");
        computer::coordinate.push_back("B1");
        computer::coordinate.push_back("B2");
        computer::coordinate.push_back("C1");
        computer::coordinate.push_back("C2");
        computer::coordinate.push_back("D1");
        computer::coordinate.push_back("D2");
        computer::coordinate.push_back("E1");
        computer::coordinate.push_back("E2");
        computer::coordinate.push_back("F1");
        computer::coordinate.push_back("F2");
        computer::coordinate.push_back("G1");
        computer::coordinate.push_back("G2");
        computer::coordinate.push_back("H1");
        computer::coordinate.push_back("H2");
       

    }
    //se nere
    else if (c == 'b')
    {
        computer::coordinate.push_back("A7");
        computer::coordinate.push_back("A8");
        computer::coordinate.push_back("B7");
        computer::coordinate.push_back("B8");
        computer::coordinate.push_back("C7");
        computer::coordinate.push_back("C8");
        computer::coordinate.push_back("D7");
        computer::coordinate.push_back("D8");
        computer::coordinate.push_back("E7");
        computer::coordinate.push_back("E8");
        computer::coordinate.push_back("F7");
        computer::coordinate.push_back("F8");
        computer::coordinate.push_back("G7");
        computer::coordinate.push_back("G8");
        computer::coordinate.push_back("H7");
        computer::coordinate.push_back("H8");
    }
    else
        throw NoCorrectInfoConstructor();
    
    
}

int computer::getSize() {
    int n = (int)computer::coordinate.size();
    return n;
}

//funzione automossa
std::string computer::autoMove(scacchiera & board1) {
    bool flag = true;
    std::vector <int> move;
    /*muovo random la pedina con l'uso della scacchiera
      il flag diventa true quando la mossa e' stata effettuata
      correttamente.In caso contrario continua a cercare di muovere fino a che 
      non muove una pedina. */

    int n = (int)computer::coordinate.size(); //dimensione del vector per estrarre random le coordinate
    std::string s1 = "";
    std::string s2 = "";
    do
    {
        
        srand((unsigned)time(0));           //scelgo random una pedina dal vector
        int r = std::rand() % (n);
        s1 = computer::coordinate.at(r);
        std::vector<int> temp = traduttore::traduci(s1+" "+s1);
        char type = board1.getPiece(temp.at(1), temp.at(2));
        
        s2 = randomMove(board1, s1, type);
        std::string daTradurre = s1 + " " + s2;
        move = traduttore::traduci(daTradurre);
        
        if (middlePieces::check(board1, move.at(0), move.at(1), move.at(2), move.at(3)))
        {
            if (board1.movePedina(move.at(0), move.at(1), move.at(2), move.at(3))) //muovo la pedina 
            {
                flag = false;
                document::add_line("log.txt", daTradurre);
                computer::coordinate[r] = s2; //aggiorno posizione pedina nel vector
            }
        }
    } while (flag);
    
    return s1+" "+s2;
}

//restituisce una posizione random all'interno della scacchiera
std::string randomPosition(std::string s) {
    char letter = 0;
    char number = 0;
    std::string position = "";

    srand((unsigned)time(0));
    letter = (std::rand() % 8) +1;
    srand((unsigned)time(0));
    number = (std::rand() % 8) +1;
    //seleziono la lettera
    if (letter == 1)
        position = "A" + (std::to_string(number));
    else if (letter == 2)
        position = "B" + (std::to_string(number));
    else if (letter == 3)
        position = "C" + (std::to_string(number));
    else if (letter == 4)
        position = "D" + (std::to_string(number));
    else if (letter == 5)
        position = "E" + (std::to_string(number));
    else if (letter == 6)
        position = "F" + (std::to_string(number));
    else if (letter == 7)
        position = "G" + (std::to_string(number));
    else if (letter == 8)
        position = "H" + (std::to_string(number));
    //ritorno la stringa che contiene una coordinata RANDOM

    return position;
}

//funzione remove piece
void computer::removePiece(const std::string s)
{
    std::string str = s.substr(3, 2);
    if (std::find(computer::coordinate.begin(), computer::coordinate.end(), str) != computer::coordinate.end()) {
           computer::coordinate.erase(std::find(computer::coordinate.begin(), computer::coordinate.end(), str));
        
    }
}
