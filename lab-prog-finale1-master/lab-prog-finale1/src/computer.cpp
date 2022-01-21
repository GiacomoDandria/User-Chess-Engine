//AUTORE: MARCO SQUARCINA

#include"computer.h"
//COSTRUTTORI
computer::computer(){                           
    throw NoCorrectInfoConstructor();                       //Se viene chiamato il costruttore senza argomenti lancia eccezione
}     
/*Questo costruttore tiene conto del colore delle pedine del giocatore. Serve per inizializzare il vector
  in modo tale che contenga le coordinate appropriate. 
  Queste coordinate verranno estratte e utilizzate per eseguire le mosse random. Saranno rimosse le coordinate delle pedine mangiate
  e aggiornate quelle delle pedine mosse. (SERVE AL COMPUTER PER SAPERE COSA "PUO'" MUOVERE).  */
computer::computer(char c) {                                
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
/*Restituisce la dimensione della lista. Questo valore verrà utilizzato per avere un indice per utilizzare
  la funzione random, che agira' sugli elementi del vector.  */
int computer::getSize() {
    int n = (int)computer::coordinate.size();
    return n;
}

/* FUNZIONE per far muovere random una pedina al computer. 
   Muovo random la pedina con l'uso della scacchiera; il flag diventa true quando la mossa e' stata effettuata
   correttamente. In caso contrario continua a cercare di muovere fino a che non muove una pedina.     */

std::string computer::autoMove(scacchiera & board1) {
    bool flag = true;
    std::vector <int> move;
    

    int n = (int)computer::coordinate.size();                   //dimensione del vector per estrarre random le coordinate
    std::string s1 = "";
    std::string s2 = "";
    
    //Continuo il ciclo fino a quando non trovo una mossa valida
    do
    {
        
        srand((unsigned)time(0));                                 //scelgo random una pedina dal vector
        int r = std::rand() % (n);
        s1 = computer::coordinate.at(r);                          //coordinate di partenza
        std::vector<int> temp = traduttore::traduci(s1+" "+s1);   //vector temporaneo per passare s1 alla funzione randomMoves
        char type = board1.getPiece(temp.at(1), temp.at(2));      //restituice il char relativo alla pedina che si sta per muovere
        
        s2 = randomMove(board1, s1, type);                        //chiamo la funzione randomMoves, la quale resituisce una posizione valida per la mossa              
        std::string daTradurre = s1 + " " + s2;
        move = traduttore::traduci(daTradurre);                   //traduco nel vector move le coordinate da stringa a intero per lavorare meglio con le matrici
        
        if (middlePieces::check(board1, move.at(0), move.at(1), move.at(2), move.at(3)))        //controllo pezzi tra la posizione di partenza e quella di arrivo
        {
            if (board1.movePedina(move.at(0), move.at(1), move.at(2), move.at(3)))              //muovo la pedina 
            {
                flag = false;                                //mossa effettuata
                document::add_line("log.txt", daTradurre);   //mossa inserita nel file log    
                computer::coordinate[r] = s2;                //aggiorno posizione nel vector
            }
        }
    } while (flag);    
    
    return s1+" "+s2;       //ritorno le coordinate della mossa
}

/*Questo e' il primo tentativo di fare una funzione che desse una posizione random all'interno della scacchiera per muovere una pedina. A
  causa della poca efficenza abbiamo creato un ulteriore funzione semi random, presente nel file randomMoves.cpp . */
std::string randomPosition(std::string s) {
    char letter = 0;               //conterra' la lettera di arrivo
    char number = 0;               //conterra' il numero di arrivo
    std::string position = "";

    srand((unsigned)time(0));
    letter = (std::rand() % 8) +1;          //scelgo random una lettera
    srand((unsigned)time(0));
    number = (std::rand() % 8) +1;          //scelgo random una colonna
    //Converto letter e number in una stringa con le coordinate appropriate
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

/*FUNZIONE remove piece.
  Riceve una stringa con le coordinate di dove e' andata una pedina avversaria. Se in quelle coordinate c'era una pedina
  della classe corrente questa sara' rimossa dal vector (Ovvero e' stata mangiata).*/
void computer::removePiece(const std::string s)
{
    std::string str = s.substr(3, 2);       //coordinate di arrivo
    if (std::find(computer::coordinate.begin(), computer::coordinate.end(), str) != computer::coordinate.end()) {       //se e' presente rimuovo
           computer::coordinate.erase(std::find(computer::coordinate.begin(), computer::coordinate.end(), str));
        
    }
}

