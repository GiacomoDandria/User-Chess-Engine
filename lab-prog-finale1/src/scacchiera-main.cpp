#include "scacchiera-main.h"

using namespace std;

int main(int argCount, char* argVec[]) {

    //Controllo numero argomenti da riga di comando
    if(argCount > 2) {
        cout << "Numero di argomenti troppo alto " << endl;
        return 1;
    }
    if(argCount == 0 || argCount == 1) {
        cout << "Inserire gli argomenti da riga di comando" << endl;
        return 1;
    }

    //VARIABILI
    char mod = ' ';   //Conserva la modalita' di gioco
    bool flag = true;
    bool vittoria = false; //La partita va avanti finchè uno dei due vince
    string temp = ""; //stringa per contenere l'inserimento cdell'utente
    scacchiera board; //Scacchiera dove verra' giocata la partita
    char dash = '|';
    
    string argV = argVec[1];
    if(argV.compare("pc") == 0) {
	mod = 'u';
    }
    else if(argV.compare("cc") == 0) {
	mod = 'c';
    }
    else {
	cout << "ArgV non corretto" << endl;
        return 1;
    }
    
    //INIZIO CASI PARTITA
    switch(mod) {
    //Caso computer vs computer
    case('c'): {
        computer a('w'); //Virtual white
        computer b('b'); //Virtual black
        int cont = 0; //contatore mosse
        string temp = " "; //stringa temporanea per conservare le coordinate
        cout << "Sto giocando... (ci vuole qualche secondo)" << endl;
        while (cont < 50 && !vittoria) {
            temp = a.autoMove(board);
            b.removePiece(temp);

            document::add_line("log.txt", temp);

            //Verifico se il re BIANCO e' stato mangiato
            if (board.checkWin('R')) {
                cout << "\n Vittoria BIANCHI" << endl;
                vittoria = true; //Fine partita
                break;
            }

            //Verifico se il re NERO e' stato mangiato
            if (board.checkWin('r')) {
                cout << "\n Vittoria NERI" << endl;
                vittoria = true; //Fine partita
                break;
            }
            cont++;
        }
	
        //Caso partita nulla
        if (cont >= 50) {
            cout << "\nPARTITA NULLA: 50 giocate effettuate." << endl;
        }
        break;
    }
    //Caso computer vs utente
    case('u'): {
        //VARIABILI
        srand((unsigned)time(0));
        int ran = rand() % 2; //valore int per la scelta w & b random
        int cont = 0; //contatore per il numero di mosse (PER DEBUG)
        char colora = ' '; //colore giocatore A
        char colorb = ' '; //colore giocatore B
        char rea = ' ';
        char reb = ' ';
        bool fineturno = true; //bool per gestire il turno dell'utente
        vector <int> move; //conserva le mosse riechieste dall'utente
        string request = ""; //conserva le richieste dell'utente
       
        //RANDOM colori pc vs user
        if (ran == 1) {
            colora = 'w';
            colorb = 'b';
        }
        else {
            colora = 'b';
            colorb = 'w';
        }
        //Inizializzazione giocatori
        computer utente (colora);
        computer computer (colorb);

        flag = true; //riutilizzo il flag iniziale per far giocare prima il bianco

        cout << "UTENTE: " << colora << "  COMPUTER: " << colorb << endl;;
       
        //INIZIO GIOCATA
        if (colora == 'w') //se l'utente e' bianco gioca per primo
            flag = false;

        while (!vittoria) {
            fineturno = true;
            request = "";
            //Gioca l'utente
            if (flag == false) { //utile per far giocare prima il bianco

                while (fineturno) {
                    cout << "Inserire le coordinate: ";

                    //Buffer clear & input delle coordinate
                    cin.clear();
                    getline(cin, request); //stringa contenente le coordinate
                    if (request.compare("XX XX") == 0 || request.compare("xx xx") == 0) {
                        cout << "\n";
                        board.printScacchiera();
                        cout << "\n";
                    }   
                    else {
                        cout << "\n";
                       
                        move = traduttore::traduci(request); //traduco le coordinate in modo tale da usare move 
                        //controllo pedina bianca
                        if (colora == 'w') {
                            rea = 'r';
                            reb = 'R';
                            char t = board.getPiece(move.at(1), move.at(0));
                            string temp(1, t);
                            string str = " ptadrc";

                                if (str.find(temp)>0 && str.find(temp)<9) {
                                    /*Se la mossa viene eseguita, fine turno, altrimenti richiedi le coordinate*/
                                    if (middlePieces::check(board, move.at(0), move.at(1), move.at(2), move.at(3))) {
                                        if (!(board.movePedina(move.at(0), move.at(1), move.at(2), move.at(3)))) {
                                            cout << "\n   Coordinate non consentite, riprovare \n\n";
                                        }
                                        else
                                            fineturno = false;
                                    }
                                    else {
                                        cout << "\n   Coordinate non consentite, riprovare \n\n";
                                    }  
                                }   
                                else {
                                    cout << "\n   Coordinate non consentite, riprovare \n\n";
                                }
                            }
                            
                        //controllo pedina nera
                        if (colora == 'b') {
                                rea = 'R';
                                reb = 'r';
                                char t = board.getPiece(move.at(1), move.at(0));
                                string temp (1,t);
                                string str = " PTDRAC";
                                if (str.find(temp) > 0 && str.find(temp) < 9) {
                                    /*Se la mossa viene eseguita, fine turno, altrimenti richiedi le coordinate*/
                                    if (middlePieces::check(board, move.at(0), move.at(1), move.at(2), move.at(3))) {
                                        if (!(board.movePedina(move.at(0), move.at(1), move.at(2), move.at(3)))) {
                                            cout << "\n   Coordinate non consentite, riprovare \n\n";
                                        } 
                                        else
                                            fineturno = false;
                                    }
                                    else {
                                        cout << "\n   Coordinate non consentite, riprovare \n\n";
                                    }
                                }
                                else {
                                    cout << "\n   Coordinate non consentite, riprovare \n\n";
                                }
                            }
                    }
                }
            }
            //CONTROLLO VITTORIA UTENTE
            if (board.checkWin(reb)) {
                cout << "\n --L'UTENTE HA VINTO--" << endl;
                vittoria = true; //Fine partita
                break;
            }
            //CONTROLLO COMPUTER SOTTO SCACCO
            if (flag == false) {
                if (scacco::check(board, reb))
                    cout << "\n  SCACCO AL COMPUTER" << endl;
            }

            //Gioca il computer
            computer.autoMove(board);

            //CONTROLLO VITTORIA COMPUTER
            if (board.checkWin(reb)) {
                cout << "\n --IL COMPUTER HA VINTO--" << endl;
                vittoria = true; //Fine partita
                break;
            }
            
            //CONTROLLO UTENTE SOTTO SCACCO
            if (flag == false) {
                if (scacco::check(board, rea))
                    cout << "\n  SCACCO ALL'UTENTE" << endl;
            }
            
            //Fine ciclo turno
            flag = false;
            cont++;

            //Stampa su file
            document::add_line("log.txt", request);
        }
        break;
    }
    }

    cout << "\n\n\n"; //Per prendere spazio dal fondo
    
}
