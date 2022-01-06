#include <iostream>
#include<vector>
#include<limits>
#include<iostream>
#include"traduttore.h"
#include "scacchiera.h"
#include "pedone.h"
#include "alfiere.h"
#include "regina.h"
#include "re.h"
#include "cavallo.h"
#include "torre.h"
#include"middlePieces.h"
#include"computer.h"
#include "scacco.h"



using namespace std;
/*TODO: Sistemo i due input, o trovo il modo pulendo lo stream o leggendo una stringa al posto che il 
        carattere dal primo input*/

int main() {
    char mod = ' ';   //Conserva la modalita' di gioco
    bool flag = true;
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
        cin >> mod;
        if (mod == 'c' || mod == 'C' || mod == 'u' || mod == 'U' || mod == 'q' || mod == 'Q')
            flag = false;
        else {
            cout << "\n  -----------------------------------\n";
            cout << "\n  Carattere non corretto, RIPROVA\n";
            cout << "\n  -----------------------------------\n\n";
            cout << "  Scegli la modalita' di gioco: ";
        }
        
    } 
    cout << "\n-----------------------------------------------------------------------\n"; 

    //-------------------
    //INIZIO CASI PARTITA
    //-------------------
    switch (mod)
    {
    //Quit case
    case('q'): case('Q'): {
        cout << "\n        QUIT, BYE   \n\n\n";
        return 0;
    }

    //Caso computer vs computer
    case('c'): case ('C'): {
        computer a('w');       //Virtual white
        computer b('b');        //Virtual black
        int cont = 0;          //contatore mosse
        string temp = " ";     //stringa temporanea per conservare le coordinate

        while (cont < 1) {
            temp = a.autoMove(board);
            b.removePiece(temp);
            temp = b.autoMove(board);
            a.removePiece(temp);
            cont++;
        }
        board.printScacchiera();
        
        break;
    }
    
    //Caso computer vs utente
    case('u') : case ('U'):{
        //VARIABILI
        srand((unsigned)time(0));
        int ran = rand() % 2;        //valore int per la scelta w & b random
        int cont = 0;                //contatore per il numero di mosse (PER DEBUG)
        char colora = 'w';           //colore giocatore A
        char colorb='w';             //colore giocatore B
        vector <int> move;           //conserva le mosse riechieste dall'utente
        string request = "";         //conserva le richieste dell'utente


        //Random colori pc vs user
        if (ran == 1) {
            colora = 'w';
            colorb = 'b';
        }
        else {
            colora = 'b';
            colorb = 'w';
        }
        //inizializzazione
        computer utente (colora);
        computer computer (colorb);

        flag = true;               //riutilizzo il flag iniziale per far giocare prima il bianco
        cout << "\n   w = WHITE   b=BLACK ";
        cout << "   Coordinate: (LN LN)  Scacchiera: (XX XX)\n";
        cout << "\n-----------------------------------------------------------------------\n";
        cout << "\n     UTENTE: " << colora << "  COMPUTER: " << colorb<<"\n\n";
       

        //INIZIO GIOCATA
        if (colora == 'w')                                                 //se bianco l'utente gioca per primo
            flag = false;

        while (cont < 10) {
            request = "";
            if (flag == false) {                                            //utile per far giocare prima il bianco
                cout << "------TOCCA ALL' UTENTE------\n";
                cout << "  Inserire le coordinate: ";

                //Buffer clear & input delle coordinate
                cin.clear();
                fflush(stdin);
                getline(cin, request);                                      //stringa contenente le coordinate
                if (request.compare("XX XX") == 0 || request.compare("xx xx") == 0)
                    board.printScacchiera();
                

                //move = traduttore::traduci(request);//traduco le coordinate in modo tale da usare move 
                //while (board.movePedina(move.at(0), move.at(1), move.at(2), move.at(3))) {
                //    cout << "  Coordinate non consentite, riprovare:";
                //}
                
            }
            //gioca il computer
            cout << "\n------GIOCATA DEL COMPUTER-----\n\n\n";
            computer.autoMove(board);
            //board.printScacchiera();

            
            flag = false;
            cont++;
        }



        break;
    }
        
    }



    cout << "\n\n\n"; // Per prendere spazio dal fondo
}
