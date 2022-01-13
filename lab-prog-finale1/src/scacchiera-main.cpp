#include "scacchiera-main.h"

using namespace std;
/*TODO: Sistemo input deve essere cc & uc  */

int main() {

    //VARIABILI
    char mod = ' ';   //Conserva la modalita' di gioco
    bool flag = true;
    bool vittoria = false; //La partita va avanti finchè uno dei due vince
    string temp = ""; //stringa per contenere l'inserimento dell'utente
    scacchiera board; //Scacchiera dove verra' giocata la partita
    

    //RICHIESTA
    //Richiesta modalità gioco
    cout << "\n  --------------------------------------";
    cout << "\n  BENVENUTO NELLA SCACCHIERA ELETTRONICA";
    cout << "\n  --------------------------------------";
    cout << "\n\n  C (Computer VS Computer) o U(Computer VS Utente) o q(Quit)\n\n";
    cout << "  Scegli la modalita' di gioco: ";
    //controllo correttezza modalita'
    while (flag) {   
        cin.clear();
        getline(cin,temp);

        if (temp.length() > 2)          //controllo che l'input sia solo di un char
            mod = 's';
        else
            mod = temp[0];

        if (mod == 'c' || mod == 'C' || mod == 'u' || mod == 'U' || mod == 'q' || mod == 'Q')
            flag = false;
        else {
            cout << "\n  -----------------------------------\n ";
            cout << "\n  Carattere non corretto, RIPROVA\n";
            cout << "\n  -----------------------------------\n\n";
            cout << "  Scegli la modalita' di gioco: ";
        }
        
    } 
    cout << "\n-----------------------------------------------------------------------\n"; 

    //---------------------
    //INIZIO CASI PARTITA
    //---------------------
    switch (mod)
    {
    //Quit case
    case('q'): case('Q'): {
        cout << "\n        QUIT, BYE!   \n\n\n";
        return 0;
    }

    //Caso computer vs computer
    case('c'): case ('C'): {
        computer a('w');                    //Virtual white
        computer b('b');                    //Virtual black
        int cont = 0;                       //contatore mosse
        string temp = " ";                  //stringa temporanea per conservare le coordinate
        while (cont < 50 && !vittoria) {
            temp = a.autoMove(board);
            b.removePiece(temp);

            //Verifico se il re BIANCO e' stato mangiato
            if (board.checkWin('R')) {
                cout << "\n Vittoria BIANCHI" << endl;
                vittoria = true; //Fine partita
                break;
            }
            //RIMUOVO PER DEBUG
            board.printScacchiera();
            cout << "\n";
            temp = b.autoMove(board);
            a.removePiece(temp);

            //Verifico se il re NERO e' stato mangiato
            if (board.checkWin('r')) {
                cout << "\n Vittoria NERI" << endl;
                vittoria = true; //Fine partita
                break;
            }
            //RIMUOVO PER DEBUG
            board.printScacchiera();
            cout << "\n";
            cont++;
        }
        cout << "\n\n";
        board.printScacchiera();
        break;
    }
    //Caso computer vs utente
    case('u') : case ('U'):{
        //VARIABILI
        srand((unsigned)time(0));
        int ran = rand() % 2;        //valore int per la scelta w & b random
        int cont = 0;                //contatore per il numero di mosse (PER DEBUG)
        char colora = ' ';           //colore giocatore A
        char colorb = ' ';           //colore giocatore B
        char rea = ' ';
        char reb = ' ';
        bool fineturno = true;       //bool per gestire il turno dell'utente
        vector <int> move;           //conserva le mosse riechieste dall'utente
        string request = "";         //conserva le richieste dell'utente
       
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

        flag = true;                                                       //riutilizzo il flag iniziale per far giocare prima il bianco
        cout << "\n   w = WHITE   b=BLACK ";
        cout << "   Coordinate: (LN LN)  Scacchiera: (XX XX)\n";
        cout << "\n-----------------------------------------------------------------------\n";
        cout << "\n     UTENTE: " << colora << "  COMPUTER: " << colorb<<"\n\n";
       
        //INIZIO GIOCATA
        if (colora == 'w')                                                 //se l'utente e' bianco gioca per primo
            flag = false;

        while (!vittoria) {
            fineturno = true;
            request = "";
            //Gioca l'utente
            if (flag == false) {                                            //utile per far giocare prima il bianco
                cout << "-------TOCCA ALL' UTENTE-------\n";

                while (fineturno) {
                    cout << "\n  Inserire le coordinate: ";

                    //Buffer clear & input delle coordinate
                    cin.clear();
                    getline(cin, request);                                  //stringa contenente le coordinate
                    if (request.compare("XX XX") == 0 || request.compare("xx xx") == 0) {
                        cout << "\n";
                        board.printScacchiera();
                        cout << "\n";
                    }   
                    else {
                        cout << "\n";
                       
                        move = traduttore::traduci(request);                //traduco le coordinate in modo tale da usare move 
                        //controllo pedina bianca
                        if (colora == 'w') {
                            rea = 'r';
                            reb = 'R';
                            char t = board.getPiece(move.at(1), move.at(0));
                            string temp(1, t);
                            cout << "\n STRING DA PARAGONARE:" << temp << ":::\n";
                            string str = " ptadrc";

                                if (str.find(temp)>0 && str.find(temp)<9) {
                                    std::cout << "\n SONO DENTRO AL FIND\n";
                                    /*Se la mossa viene eseguita, fine turno, altrimenti richiedi le coordinate*/
                                    if (middlePieces::check(board, move.at(0), move.at(1), move.at(2), move.at(3))) {
                                        std::cout << "\n SONO DENTRO AL MIDDLE PIECES\n";
                                        if (!(board.movePedina(move.at(0), move.at(1), move.at(2), move.at(3)))) {
                                            cout << "\n   Coordinate non consentite, riprovare \n\n";
                                            cout << "  --------------------------------------\n\n";
                                        }
                                        else
                                            fineturno = false;
                                    }
                                    else {
                                        cout << "\n   Coordinate non consentite, riprovare \n\n";
                                        cout << "  --------------------------------------\n\n";
                                    }  
                                }   
                                else {
                                    cout << "\n   Coordinate non consentite, riprovare \n\n";
                                    cout << "  --------------------------------------\n\n";
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
                                            cout << "  --------------------------------------\n\n";
                                        } 
                                        else
                                            fineturno = false;
                                    }
                                    else {
                                        cout << "\n   Coordinate non consentite, riprovare \n\n";
                                        cout << "  --------------------------------------\n\n";
                                    }
                                }
                                else {
                                    cout << "\n   Coordinate non consentite, riprovare \n\n";
                                    cout << "  --------------------------------------\n\n";
                                }
                            }
                        
                       
                    }
                }
            }
            //CONTROLLO VITTORIA UTENTE
            if (board.checkWin(reb)) {
                cout << "\n --L' UTENTE HA VINTO--" << endl;
                vittoria = true; //Fine partita
                break;
            }
            //CONTROLLO COMPUTER SOTTO SCACCO
            if(scacco::check(board, reb))
                  cout<<"\n  SCACCO AL COMPUTER"<< endl;

            //Gioca il computer
            cout << "\n------GIOCATA DEL COMPUTER-----\n\n\n";
            computer.autoMove(board);

            //CONTROLLO VITTORIA COMPUTER
            if (board.checkWin(reb)) {
                cout << "\n --IL COMPUTER HA VINTO--" << endl;
                vittoria = true; //Fine partita
                break;
            }
            
            //CONTROLLO UTENTE SOTTO SCACCO
            if (scacco::check(board, rea))
                cout << "\n  SCACCO ALL'UTENTE" << endl;
            

            //Fine ciclo turno
            flag = false;
            cont++;
        }
        break;
    }
    }

    cout << "\n\n\n"; // Per prendere spazio dal fondo
    
}
