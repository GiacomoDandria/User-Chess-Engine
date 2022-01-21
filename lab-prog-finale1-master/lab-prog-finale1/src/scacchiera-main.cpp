//Autore: Giacomo D'Andria

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

    //Variabili che serviranno durante la partita
    char mod = ' '; //Conserva la modalita' di gioco
    bool flag = true; //
    bool vittoria = false; //La partita va avanti finchè uno dei due vince
    string temp = ""; //stringa per contenere l'inserimento cdell'utente
    scacchiera board; //Scacchiera dove verra' giocata la partita
    document::clear_doc("log.txt"); //pulisce un eventuale file di log gia' presente
    
    /*controllo che sia presente, come argV, un valore valido, altrimenti il programma termina.
      gli argomenti da riga di comando possono essere pc o cc, rispettivamente modalita'
      utente vs. computer (u) o modalita' computer vs. computer (c)*/
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
	    
        computer a('w'); //Assegno a un computer le pedine bianche
        computer b('b'); //Assegno all'altro computer quelle nere
        int cont = 0; //contatore mosse
        int contatorep = 0; //serve per il controllo dell'en passant
        int contatoreP = 0; //serve per il controllo dell'en passant
        string temp = ""; //stringa temporanea per conservare le coordinate
        cout << "Sto giocando... (ci vuole qualche secondo)" << endl;
	    
	/*Il ciclo continua a ripetersi finche' non avviene la vittora di una delle due
	  parti, neri o bianchi, oppure finche' non avviene la patta o, se nessuno
	  dei precedenti casi si verifica, finche' non vengono eseguite un massimo
	  di 50 mosse (a testa)*/
        while (cont < 50 && !vittoria) {
            temp = a.autoMove(board); //automossa del computer A
            b.removePiece(temp); //rimuovo il pezzo mangiato
		
            //Verifico se il re NERO e' stato mangiato
            if (board.checkWin('R')) {
                cout << "\nVittoria NERI!" << endl;
                vittoria = true; //Fine partita
                break;
            }
		
            //Verifico se e' scaccomatto
            if(scacco::check(board, 'R'))
                if(scaccomatto::check(board)){
                        cout << "\nSCACCO MATTO!" << endl;
                        return 0; //il programma termina perche' la partita e' finita
            }
            
	    //Verifico se e' stata fatta la patta
            if (board.scacchiera::pattaCheck()) {
                cout << "\nPATTA!" << endl;
                break;
            }
	    
	    //Verifico se e' stato fatto en passant
	    /*La verifica dell'en passant deve essere fatta in base a cio' che avviene
	      durante il turno successivo: il programma controlla quindi se la scacchiera
	      e' in una situazione in cui potrebbe avvenire l'en passant. In caso positivo
	      aggiorna contatoreP o contatorep a 1, in modo tale da tenerne conto durante
	      l'esecuzione del ciclo successivo. Durante il ciclo successivo, se il
	      contatore e' uguale a 1, la flag viene rimessa a false e il contatore
	      riportato a zero. In questo modo, nell'iterazione seguente, se non si ripresenta la
	      possibilita' di fare l'en passant nuovamente, tale pezzo di codice viene ignorato*/
            if(board.enPassantFlagPGet() == true) {
		if(contatoreP == 1) {
		    board.enPassantFlagPSet(false);
		    contatoreP = 0;
		    break;
            	}
                contatoreP++;
            }
	    
            if(board.enPassantFlagpGet() == true) {
		if(contatorep == 1) {
                    board.enPassantFlagpSet(false);
                    contatorep = 0;
		    break;
                }
                contatorep++;
            }
	    
	    //Viene aggiunta la mossa appena eseguita all'interno del file di log
            document::add_line("log.txt", temp);

	    temp = b.autoMove(board); //Automossa del computer B
            a.removePiece(temp); //Rimuovo il pezzo mangiato
		
            //Verifico se il re BIANCO e' stato mangiato
            if (board.checkWin('r')) {
                cout << "\nVittoria BIANCHI!" << endl;
                vittoria = true; //Fine partita
                break;
            }
		
	    //Verifico se e' scaccomatto
            if(scacco::check(board, 'R'))
                if(scaccomatto::check(board)){
                        cout<<"\n SCACCO MATTO "<<endl;
                        return 0;
            }
		
            //Verifico se s' stata fatta la patta
            if (board.scacchiera::pattaCheck()) {
                cout << "\nPATTA!" << endl;
                break;
            }
            
	    //Ogni giocatore ha fatto una mossa: aggiorno il contatore
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
        
        srand((unsigned)time(0));
        int ran = rand() % 2; //valore int per la scelta w & b random
        char colora = ' '; //colore giocatore A
        char colorb = ' '; //colore giocatore B
        char rea = ' ';
        char reb = ' ';
        bool fineturno = true; //bool per gestire il turno dell'utente
        vector<int> move; //conserva le mosse riechieste dall'utente
        string request = ""; //conserva le richieste dell'utente
        int contatorep = 0; //serve per il controllo dell'en passant
        int contatoreP = 0; //serve per il controllo dell'en passant

        if(board.enPassantFlagPGet() == true) {
            if(contatoreP == 1) {
                board.enPassantFlagPSet(false);
                contatoreP = 0;
		break;
            }
            contatoreP++;
        }
        if(board.enPassantFlagpGet() == true) {
            if(contatorep == 1) {
                board.enPassantFlagpSet(false);
                contatorep = 0;
		break;
            }
            contatorep++;
        }
       
        //Assegnazione random colori pc e utente
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
        if (colora == 'w') { //se l'utente e' bianco gioca per primo
            flag = false;
	}

        while (!vittoria) {
            fineturno = true;
            request = ""; //conterra' l'input dell'utente
		
            //Gioca l'utente
            if (flag == false) { //utile per far giocare prima il bianco

                while (fineturno) {
                    cout << "Inserire le coordinate: ";

                    //Buffer clear & input delle coordinate
                    cin.clear();
                    getline(cin, request); //stringa contenente le coordinate
		
		    //controllo se il giocatore vuole stampare la scacchiera
                    if (request.compare("XX XX") == 0 || request.compare("xx xx") == 0) {
                        cout << endl;
                        board.printScacchiera();
                        cout << endl;
                    }   
                    else {
                        cout << endl;
                       
			//traduco le coordinate fornite dall'utente nel sistema di riferimento della scacchiera
                        move = traduttore::traduci(request);
			    
                        //controllo pedina bianca, e assegno si conseguenza la tipologia di pedine (i re)
                        if (colora == 'w') {
                            rea = 'r';
                            reb = 'R';
			    
			    //prendo la prima coordinata (lettera, numero) della mossa inserita dall'utente
                            char t = board.getPiece(move.at(1), move.at(0));
			    
			    /*se tale mossa prende in considerazione una pedina valida,
			      in base al colore assegnato, allora la mossa viene eseguita (naturalmente
			      vengono fatti anche altri controlli per la correttezza della mossa, solo
			      che essi sono delegati a delle altre classi)*/
                            string temp(1, t);
                            string str = " ptadrc";
                                if (str.find(temp)>0 && str.find(temp)<9) {
                                    //Se la mossa viene eseguita, fine turno, altrimenti richiedi le coordinate
                                    if (middlePieces::check(board, move.at(0), move.at(1), move.at(2), move.at(3))) {
                                        if (!(board.movePedina(move.at(0), move.at(1), move.at(2), move.at(3)))) {
                                            cout << "\nCoordinate non consentite, riprovare!" << endl;
                                        }
                                        else
                                            fineturno = false;
                                    }
                                    else {
                                        cout << "\nCoordinate non consentite, riprovare!" << endl;
                                    }  
                                }   
                                else {
                                    cout << "\n   Coordinate non consentite, riprovare \n\n";
                                }
                            }
                            
                        //controllo pedina nera, e assegno si conseguenza la tipologia di pedine (i re)
                        if (colora == 'b') {
				rea = 'R';
				reb = 'r';

				//prendo la prima coordinata (lettera, numero) della mossa inserita dall'utente
				char t = board.getPiece(move.at(1), move.at(0));

				//stesso controllo di riga 238 ma con le altre pedine
				string temp (1, t);
				string str = " PTDRAC";
				if (str.find(temp) > 0 && str.find(temp) < 9) {
				    //Se la mossa viene eseguita, fine turno, altrimenti richiedi le coordinate
				    if (middlePieces::check(board, move.at(0), move.at(1), move.at(2), move.at(3))) {
					if (!(board.movePedina(move.at(0), move.at(1), move.at(2), move.at(3)))) {
					    cout << "\nCoordinate non consentite, riprovare!" << endl;
					} 
					else
					    fineturno = false;
				    }
				    else {
					cout << "\nCoordinate non consentite, riprovare!" << endl;
				    }
				}
				else {
				    cout << "\nCoordinate non consentite, riprovare!" << endl;
				}
                        }
                    }
                }
            }
		
            //Verifico se l'utente ha vinto
            if (board.checkWin(reb)) {
                cout << "\nL'UTENTE HA VINTO!" << endl;
                vittoria = true; //Fine partita
                break;
            }
		
	    //Controllo se e' stata fatta la patta
            if (board.scacchiera::pattaCheck()) {
                cout << "\nPATTA!" << endl;
                break;
            }
		
            //Controllo se il computer e' sotto scacco
            if (flag == false) {
                if (scacco::check(board, reb)) { 
                    if(scaccomatto::check(board)){
                        cout << "\nSCACCO MATTO, L'UTENTE VINCE!" << endl;
                        return 0;
                    }
                    cout << "\nSCACCO AL COMPUTER!" << endl;
                }
            }

            //E' il turno del computer: fa una mossa casuale
            computer.autoMove(board);

            //Controllo se il computer ha vinto
            if (board.checkWin(reb)) {
                document::add_line("log.txt", request); //Anche con lo scacco l'ultima mossa viene salvata
                cout << "\nIL COMPUTER HA VINTO!" << endl;
                vittoria = true; //Fine partita
            }
		
            //Controllo se e' stata fatta la patta
            if (board.scacchiera::pattaCheck()) {
                cout << "\nPATTA!" << endl;
            }
		
            //Controllo se l'utente e' sotto scacco
            if (flag == false) {
                if (scacco::check(board, rea)) {
                    if(scaccomatto::check(board)){
                        document::add_line("log.txt", request);  //Anche con lo scacco l'ultima mossa viene salvata
                        cout<<"\nSCACCO MATTO, COMPUTER VINCE!"<<endl;
                        return 0;
                    }
                    cout << "\nSCACCO ALL'UTENTE!" << endl;
                }
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

    cout << endl"; //Per prendere spazio dal fondo
    
}
